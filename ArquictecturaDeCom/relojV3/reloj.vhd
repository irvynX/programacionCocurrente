library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity reloj is
	port(
    clk: in std_logic;  --reloj
    stop: in std_logic; --detiene el reloj
    btnIzq: in std_logic; --boton para cambiar minutos
    btnDer: in std_logic; --boton para cambiar hora
	 btnRst: in std_logic; --boton para reiniciar el reloj
	 btnAlarma: in std_logic; --boton para guardar un tiempo para alarma#
	 alarma: out std_logic; --enciende led para indicar la alarma
    
    segmento: out std_logic_vector(7 downto 0); --segmento
    anodo: out std_logic_vector(3 downto 0); --anodo
    led: out std_logic_vector(7 downto 0) --leds
);
end reloj;

architecture Behavioral of reloj is
	
	--Segmento (display)
	type segmento_recorrido_vector is array (0 to 9) of std_logic_vector(6 downto 0);
	--punto
	type punto_recorrido_vector is array (0 to 19) of std_logic_vector(3 downto 0);
	--segundos digito
	type segmento_digito_vector is array (3 downto 0) of unsigned(6 downto 0);
	
	constant uno: std_logic_vector(3 downto 0) := "0001"; --Valor 1 en binario
	
	--Tomamos en cuenta el tiempo necesario para que cambie al siguiente digito
	--50000000, 1000000, 48000000
	constant ticks_por_segundo: unsigned(25 downto 0) := to_unsigned(50000000	, 26);
	
	--Establecemos los valores que corresponden a los 7 segmentos en cada valor del 0 al 9
	constant segmento_recorrido: segmento_recorrido_vector := (
    0 => "1000000", 
	 1 => "1111001", 
	 2 => "0100100", 
	 3 => "0110000", 
	 4 => "0011001",
    5 => "0010010", 
	 6 => "0000010", 
	 7 => "1111000", 
	 8 => "0000000", 
	 9 => "0011000"
	);
	
	--Esto solo es para visulizar como el punto que se encuentra al lado del display se mueve conforme al tiempo
	--De la misma forma es para el contador 
	constant punto_recorridos: punto_recorrido_vector := (
    0 => "1111", 
    1 => "1110",  
	 2 => "1101",  
	 3 => "1011",  
	 4 => "0111",
    5 => "0110",  
	 6 => "0101",  
	 7 => "0011",
    8 => "0010",  
	 9 => "0001",
    10 => "0000",
    11 => "0001", 
	 12 => "0010",
    13 => "0011", 
	 14 => "0101", 
	 15 => "0110",
    16 => "0111", 
	 17 => "1011", 
	 18 => "1101", 
	 19 => "1110"
	);
	
	--Asignamos 
	signal led_registro: std_logic_vector(4 downto 0) := (others => '0');
	signal pendulo: std_logic_vector(1 downto 0) := "01";
 
	signal contador: unsigned(20 downto 0);
	signal segundo_tick: unsigned(ticks_por_segundo'range) := ticks_por_segundo;
 
	--10 Unidades
	signal contador_diez_segundos: unsigned(3 downto 0) := (others => '0');
	signal contador_diez_unidades: unsigned(2 downto 0) := (others => '0');
	signal puntos_index: unsigned(4 downto 0) := (others => '0');
 
	--Horas y minutos
	signal hora_alto: unsigned(1 downto 0) := (others => '0');
	signal hora_bajo: unsigned(3 downto 0) := (others => '0');
	signal min_alto: unsigned(2 downto 0) := (others => '0');
	signal min_bajo: unsigned(3 downto 0) := (others => '0');
	
	--Horas y minutos para la alarma
	signal ha_alarma: unsigned(1 downto 0):= (others => '0');
	signal hb_alarma: unsigned(3 downto 0):= (others => '0');
	signal ma_alarma: unsigned(2 downto 0):= (others => '0');
	signal mb_alarma: unsigned(3 downto 0):= (others => '0');
	
	--punto que recorre en los leds
	signal punto_recorrido: std_logic_vector(3 downto 0);
	signal segmento_digitos: segmento_digito_vector;
	
	--Botonos para cambiar horas y minutos, reset y alarma
	signal btnIzq_registro: std_logic_vector(1 downto 0) := (others => '0');
	signal btnDer_registro: std_logic_vector(1 downto 0) := (others => '0');
	signal btnRst_registro: std_logic_vector(1 downto 0) := (others => '0');
	signal btnAlarma_registro: std_logic_vector(1 downto 0) := (others => '0');--##
 

begin

	--Inicializamos el punto desde el led donde se ubica la hora en alto
	 punto_recorrido <= punto_recorridos(to_integer(puntos_index));
	 --Inicializamos los valores para la hora y minuto tanto en alto como en bajo
    segmento_digitos <= ("00000" & hora_alto, "000" & hora_bajo, "0000" & min_alto, "000" & min_bajo);
    
    --sll:(desplazamiento lógico, a la izquierda o a la derecha). Desplaza un vector un número
    --de bits a izquierda o derecha rellenando con ceros los huecos libres.
	 anodo(3 downto 0) <= not std_logic_vector(unsigned(uno) sll to_integer(contador(17 downto 16)));
    segmento(7) <= punto_recorrido(to_integer(contador(17 downto 16)));
    segmento(6 downto 0) <= segmento_recorrido(to_integer(segmento_digitos(to_integer(contador(17 downto 16)))));
    led <= led_registro & "0" & pendulo;
	 
--Proceso para el reloj	 
	 process (clk)
    begin
		--Flaco de subida 
        if rising_edge(clk) then
            contador <= contador + 1;
            
				--Si el switch de stop esta apagado, el reloj correra normalmente 
            if stop = '0' then
				--Comenzamos por el incremento de los segundos, y hacemos la funcíon del pendulo
                if segundo_tick = 0 then
                    segundo_tick <= ticks_por_segundo;
                    contador_diez_segundos <= contador_diez_segundos + 1;
                    pendulo <= not pendulo;
                
					 -- Esto corresponde al segmento del punto que recorre en la tarjeta.
					 --Llega a su maximo y vuelve a empezar
                    if puntos_index = 19 then
                       puntos_index <= (others => '0');
                    else
						  --continua incrementando
                        puntos_index <= puntos_index + 1;
                    end if;
                else
                    segundo_tick <= segundo_tick - 1;
                end if;
            end if;
            
				--Al inicializar el contador, asignamos el punto de partida para los botones
            if contador = 0 then
                btnIzq_registro <= btnIzq_registro(0) & btnIzq;
                btnDer_registro <= btnDer_registro(0) & btnDer;
					 btnRst_registro <= btnRst_registro(0) & btnRst;
					 btnAlarma_registro <= btnAlarma_registro(0) & btnAlarma; --##
                
					 --Si el boton de la derecha (minutos) conserva el mismo valor, puede hacer un incremento en 1
					 --Es decir, podemos presionar para ajustar los minutos.
                if btnDer_registro = "01" then
                    min_bajo <= min_bajo + 1;
                end if;
                
					 --De la misma forma, pero para el boton de la izquierda(Horas)
                if btnIzq_registro = "01" then
                    hora_bajo <= hora_bajo + 1;
                end if;
					 
					 --Boton reset para reiniciar el reloj
					 if btnRst_registro = "01" then
						 --contador <= contador-contador;
						 --segundo_tick <= segundo_tick - segundo_tick;
						 --puntos_index <= (others => '0');
						 --contador_diez_segundos <= (others => '0');
						 --contador_diez_unidades <= (others => '0');
						 contador <= contador-contador;
						 segundo_tick <= segundo_tick - segundo_tick;
						 puntos_index <= puntos_index - puntos_index;
						 contador_diez_segundos <= contador_diez_segundos - contador_diez_segundos;
						 contador_diez_unidades <= contador_diez_unidades - contador_diez_unidades;
						 hora_alto <= hora_alto - hora_alto;
						 hora_bajo <= hora_bajo - hora_bajo;
						 min_alto <= min_alto - min_alto;
						 min_bajo <= min_bajo - min_bajo;
					 end if;
					 
					 --Boton alarma ##
					 if btnAlarma_registro = "01" then
						 ha_alarma <= hora_alto;
						 hb_alarma <= hora_bajo;
						 ma_alarma <= min_alto;
						 mb_alarma <= min_bajo;
					 end if;
					 
            end if;

------------------------------------------------------------------------------------------------------------------	
--Para los segundos:
			
				--Unidades de segundo
            if contador_diez_segundos = 10 then
					--Al llegar al valor maximo reincia para empezar otra vez
                contador_diez_segundos <= (others => '0');
                contador_diez_unidades <= contador_diez_unidades + 1;
					 --Al finalizar enciende un led para indicar el conteo finalizado
                led_registro(4 downto 0) <= '1' & led_registro(4 downto 1);
            end if;
                
				--Decenas de segundo	 
            if contador_diez_unidades = 6 then
                --Al llegar a los 60 segundos, vuelve a empezar
					 contador_diez_unidades <= (others => '0');
					 --Enciende los leds
                led_registro(4 downto 0) <= (others => '0');
					 --Incrementa a 1 el valor actual del minuto (bajo)
                min_bajo <= min_bajo + 1;
            end if;

------------------------------------------------------------------------------------------------------------------	
--Para los minutos:

				--Cuando el valor bajo del minuto llegue a 10
            if min_bajo = 10 then
					--Inicializamos nuevamente el valor de minuto bajo
                min_bajo <= (others => '0');
					 --Hacemos un incremento en el minuto en alto.
					 --Por ejemplo: del 09 sube a 10, del 29 sube a 30.
                min_alto <= min_alto + 1;
            end if;
            
				--De la misma forma para minuto en alto
            if min_alto = 6 then
                min_alto <= (others => '0');
			   --Solo que ahora, el valor de hora en bajo incrementa
                hora_bajo <= hora_bajo + 1;
            end if;

------------------------------------------------------------------------------------------------------------------	
--Para las horas:
            
				--Si hora en bajo llega a 10, realiza lo mismo hecho en minuto bajo
            if hora_bajo = 10 then
                hora_bajo <= (others => '0');
                hora_alto <= hora_alto + 1;
            end if;
            
				--Cuando el tiempo llegue a 23:59, no marcará 24:00, sino 0:00
            if hora_alto = 2 and hora_bajo = 4 then
                hora_alto <= (others => '0');
                hora_bajo <= (others => '0');
            end if;
        end if;
    end process;

------------------------------------------------------------------------------------------------------------------	 
--Activar Alarma
  --process(hora_alto, hora_bajo, min_alto, min_bajo)
  --begin
	--if(hora_alto="000" and hora_bajo="0111" and min_alto="000" and min_bajo="0000") or -- 7:00
	  --(hora_alto="001" and hora_bajo="0010" and min_alto="000" and min_bajo="0000") or -- 12:00
	  --(hora_alto="001" and hora_bajo="0111" and min_alto="000" and min_bajo="0000")then --17:00
		--alarma <= '1';
	--else
		--alarma <= '0';
	--end if;
  --end process;

	process(hora_alto, hora_bajo, min_alto, min_bajo, ha_alarma, hb_alarma, ma_alarma, mb_alarma)
		begin
		 if(hora_alto=ha_alarma and hora_bajo=hb_alarma and min_alto=ma_alarma and min_bajo=mb_alarma) then
			 alarma <= '1';
		 else
			 alarma <= '0';
		 end if;
   end process;

end Behavioral;

