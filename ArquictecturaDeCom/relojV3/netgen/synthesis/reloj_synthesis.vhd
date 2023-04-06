--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____
--  /   /\/   /
-- /___/  \  /    Vendor: Xilinx
-- \   \   \/     Version: P.20131013
--  \   \         Application: netgen
--  /   /         Filename: reloj_synthesis.vhd
-- /___/   /\     Timestamp: Thu Dec 01 14:39:49 2022
-- \   \  /  \ 
--  \___\/\___\
--             
-- Command	: -intstyle ise -ar Structure -tm reloj -w -dir netgen/synthesis -ofmt vhdl -sim reloj.ngc reloj_synthesis.vhd 
-- Device	: xc7a100t-3-csg324
-- Input file	: reloj.ngc
-- Output file	: C:\Users\Santiago\Documents\ISE DESIGN\relojV3\netgen\synthesis\reloj_synthesis.vhd
-- # of Entities	: 1
-- Design Name	: reloj
-- Xilinx	: C:\Xilinx\14.7\ISE_DS\ISE\
--             
-- Purpose:    
--     This VHDL netlist is a verification model and uses simulation 
--     primitives which may not represent the true implementation of the 
--     device, however the netlist is functionally correct and should not 
--     be modified. This file cannot be synthesized and should only be used 
--     with supported simulation tools.
--             
-- Reference:  
--     Command Line Tools User Guide, Chapter 23
--     Synthesis and Simulation Design Guide, Chapter 6
--             
--------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
use UNISIM.VPKG.ALL;

entity reloj is
  port (
    clk : in STD_LOGIC := 'X'; 
    stop : in STD_LOGIC := 'X'; 
    btnIzq : in STD_LOGIC := 'X'; 
    btnDer : in STD_LOGIC := 'X'; 
    btnRst : in STD_LOGIC := 'X'; 
    btnAlarma : in STD_LOGIC := 'X'; 
    alarma : out STD_LOGIC; 
    segmento : out STD_LOGIC_VECTOR ( 7 downto 0 ); 
    anodo : out STD_LOGIC_VECTOR ( 3 downto 0 ); 
    led : out STD_LOGIC_VECTOR ( 7 downto 0 ) 
  );
end reloj;

architecture Structure of reloj is
  signal clk_BUFGP_0 : STD_LOGIC; 
  signal stop_IBUF_1 : STD_LOGIC; 
  signal btnIzq_IBUF_2 : STD_LOGIC; 
  signal btnDer_IBUF_3 : STD_LOGIC; 
  signal btnRst_IBUF_4 : STD_LOGIC; 
  signal btnAlarma_IBUF_5 : STD_LOGIC; 
  signal segmento_7_OBUF_82 : STD_LOGIC; 
  signal contador_diez_unidades_2_PWR_4_o_equal_81_o : STD_LOGIC; 
  signal alarma_OBUF_84 : STD_LOGIC; 
  signal hora_bajo_3_hora_bajo_3_mux_92_OUT_3_Q : STD_LOGIC; 
  signal hora_bajo_3_hora_bajo_3_mux_92_OUT_2_Q : STD_LOGIC; 
  signal hora_bajo_3_hora_bajo_3_mux_92_OUT_1_Q : STD_LOGIC; 
  signal hora_bajo_3_hora_bajo_3_mux_92_OUT_0_Q : STD_LOGIC; 
  signal anodo_3_OBUF_89 : STD_LOGIC; 
  signal anodo_2_OBUF_90 : STD_LOGIC; 
  signal anodo_1_OBUF_91 : STD_LOGIC; 
  signal anodo_0_OBUF_92 : STD_LOGIC; 
  signal contador_20_GND_4_o_equal_28_o : STD_LOGIC; 
  signal Q_n0298 : STD_LOGIC; 
  signal segmento_6_OBUF_95 : STD_LOGIC; 
  signal segmento_5_OBUF_96 : STD_LOGIC; 
  signal segmento_4_OBUF_97 : STD_LOGIC; 
  signal segmento_3_OBUF_98 : STD_LOGIC; 
  signal segmento_2_OBUF_99 : STD_LOGIC; 
  signal segmento_1_OBUF_100 : STD_LOGIC; 
  signal segmento_0_OBUF_101 : STD_LOGIC; 
  signal N0 : STD_LOGIC; 
  signal led_2_OBUF_103 : STD_LOGIC; 
  signal Q_n0324_inv : STD_LOGIC; 
  signal Q_n0332_inv : STD_LOGIC; 
  signal Q_n0367_inv1 : STD_LOGIC; 
  signal Reset_OR_DriverANDClockEnable : STD_LOGIC; 
  signal Mcount_hora_alto_val_108 : STD_LOGIC; 
  signal Mcount_hora_alto1 : STD_LOGIC; 
  signal Mcount_contador_diez_unidades_val : STD_LOGIC; 
  signal contador_diez_segundos_3_PWR_4_o_equal_76_o_inv_inv : STD_LOGIC; 
  signal stop_inv : STD_LOGIC; 
  signal Result_0_1 : STD_LOGIC; 
  signal Result_1_1 : STD_LOGIC; 
  signal Result_2_1 : STD_LOGIC; 
  signal Result_3_1 : STD_LOGIC; 
  signal Result_4_1 : STD_LOGIC; 
  signal Result_5_1 : STD_LOGIC; 
  signal Result_6_1 : STD_LOGIC; 
  signal Result_7_1 : STD_LOGIC; 
  signal Result_8_1 : STD_LOGIC; 
  signal Result_9_1 : STD_LOGIC; 
  signal Result_10_1 : STD_LOGIC; 
  signal Result_11_1 : STD_LOGIC; 
  signal Result_12_1 : STD_LOGIC; 
  signal Result_13_1 : STD_LOGIC; 
  signal Result_14_1 : STD_LOGIC; 
  signal Result_15_1 : STD_LOGIC; 
  signal Result_16_1 : STD_LOGIC; 
  signal Result_17_1 : STD_LOGIC; 
  signal Result_18_1 : STD_LOGIC; 
  signal Result_19_1 : STD_LOGIC; 
  signal Mcount_segundo_tick_eqn_19 : STD_LOGIC; 
  signal Result_20_1 : STD_LOGIC; 
  signal Mcount_segundo_tick_eqn_20 : STD_LOGIC; 
  signal Mcount_segundo_tick_eqn_21 : STD_LOGIC; 
  signal Mcount_segundo_tick_eqn_22 : STD_LOGIC; 
  signal Mcount_segundo_tick_eqn_23 : STD_LOGIC; 
  signal Mcount_segundo_tick_eqn_25 : STD_LOGIC; 
  signal Mcount_min_alto_val : STD_LOGIC; 
  signal Mcount_puntos_index : STD_LOGIC; 
  signal Mcount_puntos_index1 : STD_LOGIC; 
  signal Mcount_puntos_index2 : STD_LOGIC; 
  signal Mcount_puntos_index3 : STD_LOGIC; 
  signal Mcount_puntos_index4 : STD_LOGIC; 
  signal Mcount_contador_diez_segundos_val : STD_LOGIC; 
  signal Q_n0359_inv : STD_LOGIC; 
  signal Mcount_min_bajo_val : STD_LOGIC; 
  signal Reset_OR_DriverANDClockEnable1_185 : STD_LOGIC; 
  signal Mmux_hora_bajo_3_hora_bajo_3_mux_92_OUT11 : STD_LOGIC; 
  signal min_bajo_3_PWR_4_o_equal_86_o_inv_inv : STD_LOGIC; 
  signal segundo_tick_25_GND_4_o_equal_13_o : STD_LOGIC; 
  signal contador_17_segmento_digitos_3_6_wide_mux_8_OUT_3_Q : STD_LOGIC; 
  signal contador_17_segmento_digitos_3_6_wide_mux_8_OUT_1_Q : STD_LOGIC; 
  signal contador_17_segmento_digitos_3_6_wide_mux_8_OUT_2_Q : STD_LOGIC; 
  signal contador_17_segmento_digitos_3_6_wide_mux_8_OUT_0_Q : STD_LOGIC; 
  signal led_0_inv : STD_LOGIC; 
  signal alarma1_277 : STD_LOGIC; 
  signal alarma2_278 : STD_LOGIC; 
  signal alarma3_279 : STD_LOGIC; 
  signal alarma4_280 : STD_LOGIC; 
  signal segundo_tick_25_GND_4_o_equal_13_o_25_Q : STD_LOGIC; 
  signal segundo_tick_25_GND_4_o_equal_13_o_25_1_282 : STD_LOGIC; 
  signal segundo_tick_25_GND_4_o_equal_13_o_25_2_283 : STD_LOGIC; 
  signal segundo_tick_25_GND_4_o_equal_13_o_25_3_284 : STD_LOGIC; 
  signal contador_20_GND_4_o_equal_28_o_20_Q : STD_LOGIC; 
  signal contador_20_GND_4_o_equal_28_o_20_1_286 : STD_LOGIC; 
  signal contador_20_GND_4_o_equal_28_o_20_2_287 : STD_LOGIC; 
  signal N5 : STD_LOGIC; 
  signal Q_n0367_inv11_289 : STD_LOGIC; 
  signal Q_n0367_inv12_290 : STD_LOGIC; 
  signal Mcount_contador_cy_1_rt_318 : STD_LOGIC; 
  signal Mcount_contador_cy_2_rt_319 : STD_LOGIC; 
  signal Mcount_contador_cy_3_rt_320 : STD_LOGIC; 
  signal Mcount_contador_cy_4_rt_321 : STD_LOGIC; 
  signal Mcount_contador_cy_5_rt_322 : STD_LOGIC; 
  signal Mcount_contador_cy_6_rt_323 : STD_LOGIC; 
  signal Mcount_contador_cy_7_rt_324 : STD_LOGIC; 
  signal Mcount_contador_cy_8_rt_325 : STD_LOGIC; 
  signal Mcount_contador_cy_9_rt_326 : STD_LOGIC; 
  signal Mcount_contador_cy_10_rt_327 : STD_LOGIC; 
  signal Mcount_contador_cy_11_rt_328 : STD_LOGIC; 
  signal Mcount_contador_cy_12_rt_329 : STD_LOGIC; 
  signal Mcount_contador_cy_13_rt_330 : STD_LOGIC; 
  signal Mcount_contador_cy_14_rt_331 : STD_LOGIC; 
  signal Mcount_contador_cy_15_rt_332 : STD_LOGIC; 
  signal Mcount_contador_cy_16_rt_333 : STD_LOGIC; 
  signal Mcount_contador_cy_17_rt_334 : STD_LOGIC; 
  signal Mcount_contador_cy_18_rt_335 : STD_LOGIC; 
  signal Mcount_contador_cy_19_rt_336 : STD_LOGIC; 
  signal Mcount_segundo_tick_cy_0_rt_337 : STD_LOGIC; 
  signal Mcount_contador_xor_20_rt_338 : STD_LOGIC; 
  signal pendulo_0_rstpot_339 : STD_LOGIC; 
  signal N7 : STD_LOGIC; 
  signal N9 : STD_LOGIC; 
  signal N10 : STD_LOGIC; 
  signal contador_diez_unidades_0_rstpot_343 : STD_LOGIC; 
  signal contador_diez_unidades_1_rstpot_344 : STD_LOGIC; 
  signal hora_alto_0_rstpot_345 : STD_LOGIC; 
  signal hora_alto_1_rstpot_346 : STD_LOGIC; 
  signal segundo_tick_0_rstpot_347 : STD_LOGIC; 
  signal segundo_tick_1_rstpot_348 : STD_LOGIC; 
  signal segundo_tick_2_rstpot_349 : STD_LOGIC; 
  signal contador_diez_unidades_2_rstpot_350 : STD_LOGIC; 
  signal min_alto_0_rstpot_351 : STD_LOGIC; 
  signal min_alto_1_rstpot_352 : STD_LOGIC; 
  signal min_alto_2_rstpot_353 : STD_LOGIC; 
  signal contador_diez_segundos_1_rstpot_354 : STD_LOGIC; 
  signal contador_diez_segundos_2_rstpot_355 : STD_LOGIC; 
  signal contador_diez_segundos_3_rstpot_356 : STD_LOGIC; 
  signal min_bajo_1_rstpot_357 : STD_LOGIC; 
  signal min_bajo_2_rstpot_358 : STD_LOGIC; 
  signal min_bajo_3_rstpot_359 : STD_LOGIC; 
  signal min_bajo_0_rstpot_360 : STD_LOGIC; 
  signal segundo_tick_3_rstpot_361 : STD_LOGIC; 
  signal segundo_tick_4_rstpot_362 : STD_LOGIC; 
  signal segundo_tick_5_rstpot_363 : STD_LOGIC; 
  signal segundo_tick_6_rstpot_364 : STD_LOGIC; 
  signal segundo_tick_8_rstpot_365 : STD_LOGIC; 
  signal segundo_tick_9_rstpot_366 : STD_LOGIC; 
  signal segundo_tick_10_rstpot_367 : STD_LOGIC; 
  signal segundo_tick_11_rstpot_368 : STD_LOGIC; 
  signal segundo_tick_16_rstpot_369 : STD_LOGIC; 
  signal segundo_tick_18_rstpot_370 : STD_LOGIC; 
  signal segundo_tick_24_rstpot_371 : STD_LOGIC; 
  signal contador_0_rstpot_372 : STD_LOGIC; 
  signal contador_1_rstpot_373 : STD_LOGIC; 
  signal contador_2_rstpot_374 : STD_LOGIC; 
  signal contador_3_rstpot_375 : STD_LOGIC; 
  signal contador_4_rstpot_376 : STD_LOGIC; 
  signal contador_5_rstpot_377 : STD_LOGIC; 
  signal contador_6_rstpot_378 : STD_LOGIC; 
  signal contador_7_rstpot_379 : STD_LOGIC; 
  signal contador_8_rstpot_380 : STD_LOGIC; 
  signal contador_9_rstpot_381 : STD_LOGIC; 
  signal contador_10_rstpot_382 : STD_LOGIC; 
  signal contador_11_rstpot_383 : STD_LOGIC; 
  signal contador_12_rstpot_384 : STD_LOGIC; 
  signal contador_13_rstpot_385 : STD_LOGIC; 
  signal contador_14_rstpot_386 : STD_LOGIC; 
  signal contador_15_rstpot_387 : STD_LOGIC; 
  signal contador_16_rstpot_388 : STD_LOGIC; 
  signal contador_17_rstpot_389 : STD_LOGIC; 
  signal contador_18_rstpot_390 : STD_LOGIC; 
  signal contador_19_rstpot_391 : STD_LOGIC; 
  signal contador_20_rstpot_392 : STD_LOGIC; 
  signal segundo_tick_7_rstpot_393 : STD_LOGIC; 
  signal segundo_tick_12_rstpot_394 : STD_LOGIC; 
  signal segundo_tick_13_rstpot_395 : STD_LOGIC; 
  signal segundo_tick_14_rstpot_396 : STD_LOGIC; 
  signal segundo_tick_15_rstpot_397 : STD_LOGIC; 
  signal segundo_tick_17_rstpot_398 : STD_LOGIC; 
  signal N12 : STD_LOGIC; 
  signal N13 : STD_LOGIC; 
  signal contador : STD_LOGIC_VECTOR ( 20 downto 0 ); 
  signal pendulo : STD_LOGIC_VECTOR ( 0 downto 0 ); 
  signal btnIzq_registro : STD_LOGIC_VECTOR ( 1 downto 0 ); 
  signal btnDer_registro : STD_LOGIC_VECTOR ( 1 downto 0 ); 
  signal btnRst_registro : STD_LOGIC_VECTOR ( 1 downto 0 ); 
  signal btnAlarma_registro : STD_LOGIC_VECTOR ( 1 downto 0 ); 
  signal ha_alarma : STD_LOGIC_VECTOR ( 1 downto 0 ); 
  signal hb_alarma : STD_LOGIC_VECTOR ( 3 downto 0 ); 
  signal ma_alarma : STD_LOGIC_VECTOR ( 2 downto 0 ); 
  signal mb_alarma : STD_LOGIC_VECTOR ( 3 downto 0 ); 
  signal segundo_tick : STD_LOGIC_VECTOR ( 25 downto 0 ); 
  signal puntos_index : STD_LOGIC_VECTOR ( 4 downto 0 ); 
  signal led_registro : STD_LOGIC_VECTOR ( 4 downto 0 ); 
  signal hora_alto : STD_LOGIC_VECTOR ( 1 downto 0 ); 
  signal Result : STD_LOGIC_VECTOR ( 25 downto 0 ); 
  signal contador_diez_unidades : STD_LOGIC_VECTOR ( 2 downto 0 ); 
  signal min_alto : STD_LOGIC_VECTOR ( 2 downto 0 ); 
  signal hora_bajo : STD_LOGIC_VECTOR ( 3 downto 0 ); 
  signal Mcount_contador_lut : STD_LOGIC_VECTOR ( 0 downto 0 ); 
  signal Mcount_contador_cy : STD_LOGIC_VECTOR ( 19 downto 0 ); 
  signal Mcount_segundo_tick_cy : STD_LOGIC_VECTOR ( 24 downto 0 ); 
  signal Mcount_segundo_tick_lut : STD_LOGIC_VECTOR ( 25 downto 1 ); 
  signal contador_diez_segundos : STD_LOGIC_VECTOR ( 3 downto 1 ); 
  signal min_bajo : STD_LOGIC_VECTOR ( 3 downto 0 ); 
begin
  XST_VCC : VCC
    port map (
      P => N0
    );
  XST_GND : GND
    port map (
      G => led_2_OBUF_103
    );
  btnDer_registro_0 : FDE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => contador_20_GND_4_o_equal_28_o,
      D => btnDer_IBUF_3,
      Q => btnDer_registro(0)
    );
  btnDer_registro_1 : FDE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => contador_20_GND_4_o_equal_28_o,
      D => btnDer_registro(0),
      Q => btnDer_registro(1)
    );
  btnIzq_registro_0 : FDE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => contador_20_GND_4_o_equal_28_o,
      D => btnIzq_IBUF_2,
      Q => btnIzq_registro(0)
    );
  btnIzq_registro_1 : FDE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => contador_20_GND_4_o_equal_28_o,
      D => btnIzq_registro(0),
      Q => btnIzq_registro(1)
    );
  btnRst_registro_0 : FDE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => contador_20_GND_4_o_equal_28_o,
      D => btnRst_IBUF_4,
      Q => btnRst_registro(0)
    );
  btnRst_registro_1 : FDE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => contador_20_GND_4_o_equal_28_o,
      D => btnRst_registro(0),
      Q => btnRst_registro(1)
    );
  btnAlarma_registro_0 : FDE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => contador_20_GND_4_o_equal_28_o,
      D => btnAlarma_IBUF_5,
      Q => btnAlarma_registro(0)
    );
  btnAlarma_registro_1 : FDE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => contador_20_GND_4_o_equal_28_o,
      D => btnAlarma_registro(0),
      Q => btnAlarma_registro(1)
    );
  led_registro_0 : FDRE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => contador_diez_segundos_3_PWR_4_o_equal_76_o_inv_inv,
      D => led_registro(1),
      R => contador_diez_unidades_2_PWR_4_o_equal_81_o,
      Q => led_registro(0)
    );
  led_registro_1 : FDRE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => contador_diez_segundos_3_PWR_4_o_equal_76_o_inv_inv,
      D => led_registro(2),
      R => contador_diez_unidades_2_PWR_4_o_equal_81_o,
      Q => led_registro(1)
    );
  led_registro_2 : FDRE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => contador_diez_segundos_3_PWR_4_o_equal_76_o_inv_inv,
      D => led_registro(3),
      R => contador_diez_unidades_2_PWR_4_o_equal_81_o,
      Q => led_registro(2)
    );
  led_registro_3 : FDRE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => contador_diez_segundos_3_PWR_4_o_equal_76_o_inv_inv,
      D => led_registro(4),
      R => contador_diez_unidades_2_PWR_4_o_equal_81_o,
      Q => led_registro(3)
    );
  led_registro_4 : FDRE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => contador_diez_segundos_3_PWR_4_o_equal_76_o_inv_inv,
      D => N0,
      R => contador_diez_unidades_2_PWR_4_o_equal_81_o,
      Q => led_registro(4)
    );
  ha_alarma_0 : FDE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => Q_n0332_inv,
      D => hora_alto(0),
      Q => ha_alarma(0)
    );
  ha_alarma_1 : FDE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => Q_n0332_inv,
      D => hora_alto(1),
      Q => ha_alarma(1)
    );
  ma_alarma_0 : FDE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => Q_n0332_inv,
      D => min_alto(0),
      Q => ma_alarma(0)
    );
  ma_alarma_1 : FDE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => Q_n0332_inv,
      D => min_alto(1),
      Q => ma_alarma(1)
    );
  ma_alarma_2 : FDE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => Q_n0332_inv,
      D => min_alto(2),
      Q => ma_alarma(2)
    );
  mb_alarma_0 : FDE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => Q_n0332_inv,
      D => min_bajo(0),
      Q => mb_alarma(0)
    );
  mb_alarma_1 : FDE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => Q_n0332_inv,
      D => min_bajo(1),
      Q => mb_alarma(1)
    );
  mb_alarma_2 : FDE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => Q_n0332_inv,
      D => min_bajo(2),
      Q => mb_alarma(2)
    );
  mb_alarma_3 : FDE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => Q_n0332_inv,
      D => min_bajo(3),
      Q => mb_alarma(3)
    );
  hora_bajo_0 : FDRE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => Q_n0367_inv1,
      D => hora_bajo_3_hora_bajo_3_mux_92_OUT_0_Q,
      R => Reset_OR_DriverANDClockEnable,
      Q => hora_bajo(0)
    );
  hora_bajo_1 : FDRE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => Q_n0367_inv1,
      D => hora_bajo_3_hora_bajo_3_mux_92_OUT_1_Q,
      R => Reset_OR_DriverANDClockEnable,
      Q => hora_bajo(1)
    );
  hora_bajo_2 : FDRE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => Q_n0367_inv1,
      D => hora_bajo_3_hora_bajo_3_mux_92_OUT_2_Q,
      R => Reset_OR_DriverANDClockEnable,
      Q => hora_bajo(2)
    );
  hora_bajo_3 : FDRE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => Q_n0367_inv1,
      D => hora_bajo_3_hora_bajo_3_mux_92_OUT_3_Q,
      R => Reset_OR_DriverANDClockEnable,
      Q => hora_bajo(3)
    );
  hb_alarma_0 : FDE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => Q_n0332_inv,
      D => hora_bajo(0),
      Q => hb_alarma(0)
    );
  hb_alarma_1 : FDE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => Q_n0332_inv,
      D => hora_bajo(1),
      Q => hb_alarma(1)
    );
  hb_alarma_2 : FDE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => Q_n0332_inv,
      D => hora_bajo(2),
      Q => hb_alarma(2)
    );
  hb_alarma_3 : FDE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => Q_n0332_inv,
      D => hora_bajo(3),
      Q => hb_alarma(3)
    );
  segundo_tick_19 : FDRE
    generic map(
      INIT => '1'
    )
    port map (
      C => clk_BUFGP_0,
      CE => stop_inv,
      D => Mcount_segundo_tick_eqn_19,
      R => Q_n0298,
      Q => segundo_tick(19)
    );
  segundo_tick_20 : FDRE
    generic map(
      INIT => '1'
    )
    port map (
      C => clk_BUFGP_0,
      CE => stop_inv,
      D => Mcount_segundo_tick_eqn_20,
      R => Q_n0298,
      Q => segundo_tick(20)
    );
  segundo_tick_21 : FDRE
    generic map(
      INIT => '1'
    )
    port map (
      C => clk_BUFGP_0,
      CE => stop_inv,
      D => Mcount_segundo_tick_eqn_21,
      R => Q_n0298,
      Q => segundo_tick(21)
    );
  segundo_tick_22 : FDRE
    generic map(
      INIT => '1'
    )
    port map (
      C => clk_BUFGP_0,
      CE => stop_inv,
      D => Mcount_segundo_tick_eqn_22,
      R => Q_n0298,
      Q => segundo_tick(22)
    );
  segundo_tick_23 : FDRE
    generic map(
      INIT => '1'
    )
    port map (
      C => clk_BUFGP_0,
      CE => stop_inv,
      D => Mcount_segundo_tick_eqn_23,
      R => Q_n0298,
      Q => segundo_tick(23)
    );
  segundo_tick_25 : FDRE
    generic map(
      INIT => '1'
    )
    port map (
      C => clk_BUFGP_0,
      CE => stop_inv,
      D => Mcount_segundo_tick_eqn_25,
      R => Q_n0298,
      Q => segundo_tick(25)
    );
  puntos_index_0 : FDRE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => Q_n0324_inv,
      D => Mcount_puntos_index,
      R => Q_n0298,
      Q => puntos_index(0)
    );
  puntos_index_1 : FDRE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => Q_n0324_inv,
      D => Mcount_puntos_index1,
      R => Q_n0298,
      Q => puntos_index(1)
    );
  puntos_index_2 : FDRE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => Q_n0324_inv,
      D => Mcount_puntos_index2,
      R => Q_n0298,
      Q => puntos_index(2)
    );
  puntos_index_3 : FDRE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => Q_n0324_inv,
      D => Mcount_puntos_index3,
      R => Q_n0298,
      Q => puntos_index(3)
    );
  puntos_index_4 : FDRE
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      CE => Q_n0324_inv,
      D => Mcount_puntos_index4,
      R => Q_n0298,
      Q => puntos_index(4)
    );
  Mcount_contador_cy_0_Q : MUXCY
    port map (
      CI => led_2_OBUF_103,
      DI => N0,
      S => Mcount_contador_lut(0),
      O => Mcount_contador_cy(0)
    );
  Mcount_contador_xor_0_Q : XORCY
    port map (
      CI => led_2_OBUF_103,
      LI => Mcount_contador_lut(0),
      O => Result(0)
    );
  Mcount_contador_cy_1_Q : MUXCY
    port map (
      CI => Mcount_contador_cy(0),
      DI => led_2_OBUF_103,
      S => Mcount_contador_cy_1_rt_318,
      O => Mcount_contador_cy(1)
    );
  Mcount_contador_xor_1_Q : XORCY
    port map (
      CI => Mcount_contador_cy(0),
      LI => Mcount_contador_cy_1_rt_318,
      O => Result(1)
    );
  Mcount_contador_cy_2_Q : MUXCY
    port map (
      CI => Mcount_contador_cy(1),
      DI => led_2_OBUF_103,
      S => Mcount_contador_cy_2_rt_319,
      O => Mcount_contador_cy(2)
    );
  Mcount_contador_xor_2_Q : XORCY
    port map (
      CI => Mcount_contador_cy(1),
      LI => Mcount_contador_cy_2_rt_319,
      O => Result(2)
    );
  Mcount_contador_cy_3_Q : MUXCY
    port map (
      CI => Mcount_contador_cy(2),
      DI => led_2_OBUF_103,
      S => Mcount_contador_cy_3_rt_320,
      O => Mcount_contador_cy(3)
    );
  Mcount_contador_xor_3_Q : XORCY
    port map (
      CI => Mcount_contador_cy(2),
      LI => Mcount_contador_cy_3_rt_320,
      O => Result(3)
    );
  Mcount_contador_cy_4_Q : MUXCY
    port map (
      CI => Mcount_contador_cy(3),
      DI => led_2_OBUF_103,
      S => Mcount_contador_cy_4_rt_321,
      O => Mcount_contador_cy(4)
    );
  Mcount_contador_xor_4_Q : XORCY
    port map (
      CI => Mcount_contador_cy(3),
      LI => Mcount_contador_cy_4_rt_321,
      O => Result(4)
    );
  Mcount_contador_cy_5_Q : MUXCY
    port map (
      CI => Mcount_contador_cy(4),
      DI => led_2_OBUF_103,
      S => Mcount_contador_cy_5_rt_322,
      O => Mcount_contador_cy(5)
    );
  Mcount_contador_xor_5_Q : XORCY
    port map (
      CI => Mcount_contador_cy(4),
      LI => Mcount_contador_cy_5_rt_322,
      O => Result(5)
    );
  Mcount_contador_cy_6_Q : MUXCY
    port map (
      CI => Mcount_contador_cy(5),
      DI => led_2_OBUF_103,
      S => Mcount_contador_cy_6_rt_323,
      O => Mcount_contador_cy(6)
    );
  Mcount_contador_xor_6_Q : XORCY
    port map (
      CI => Mcount_contador_cy(5),
      LI => Mcount_contador_cy_6_rt_323,
      O => Result(6)
    );
  Mcount_contador_cy_7_Q : MUXCY
    port map (
      CI => Mcount_contador_cy(6),
      DI => led_2_OBUF_103,
      S => Mcount_contador_cy_7_rt_324,
      O => Mcount_contador_cy(7)
    );
  Mcount_contador_xor_7_Q : XORCY
    port map (
      CI => Mcount_contador_cy(6),
      LI => Mcount_contador_cy_7_rt_324,
      O => Result(7)
    );
  Mcount_contador_cy_8_Q : MUXCY
    port map (
      CI => Mcount_contador_cy(7),
      DI => led_2_OBUF_103,
      S => Mcount_contador_cy_8_rt_325,
      O => Mcount_contador_cy(8)
    );
  Mcount_contador_xor_8_Q : XORCY
    port map (
      CI => Mcount_contador_cy(7),
      LI => Mcount_contador_cy_8_rt_325,
      O => Result(8)
    );
  Mcount_contador_cy_9_Q : MUXCY
    port map (
      CI => Mcount_contador_cy(8),
      DI => led_2_OBUF_103,
      S => Mcount_contador_cy_9_rt_326,
      O => Mcount_contador_cy(9)
    );
  Mcount_contador_xor_9_Q : XORCY
    port map (
      CI => Mcount_contador_cy(8),
      LI => Mcount_contador_cy_9_rt_326,
      O => Result(9)
    );
  Mcount_contador_cy_10_Q : MUXCY
    port map (
      CI => Mcount_contador_cy(9),
      DI => led_2_OBUF_103,
      S => Mcount_contador_cy_10_rt_327,
      O => Mcount_contador_cy(10)
    );
  Mcount_contador_xor_10_Q : XORCY
    port map (
      CI => Mcount_contador_cy(9),
      LI => Mcount_contador_cy_10_rt_327,
      O => Result(10)
    );
  Mcount_contador_cy_11_Q : MUXCY
    port map (
      CI => Mcount_contador_cy(10),
      DI => led_2_OBUF_103,
      S => Mcount_contador_cy_11_rt_328,
      O => Mcount_contador_cy(11)
    );
  Mcount_contador_xor_11_Q : XORCY
    port map (
      CI => Mcount_contador_cy(10),
      LI => Mcount_contador_cy_11_rt_328,
      O => Result(11)
    );
  Mcount_contador_cy_12_Q : MUXCY
    port map (
      CI => Mcount_contador_cy(11),
      DI => led_2_OBUF_103,
      S => Mcount_contador_cy_12_rt_329,
      O => Mcount_contador_cy(12)
    );
  Mcount_contador_xor_12_Q : XORCY
    port map (
      CI => Mcount_contador_cy(11),
      LI => Mcount_contador_cy_12_rt_329,
      O => Result(12)
    );
  Mcount_contador_cy_13_Q : MUXCY
    port map (
      CI => Mcount_contador_cy(12),
      DI => led_2_OBUF_103,
      S => Mcount_contador_cy_13_rt_330,
      O => Mcount_contador_cy(13)
    );
  Mcount_contador_xor_13_Q : XORCY
    port map (
      CI => Mcount_contador_cy(12),
      LI => Mcount_contador_cy_13_rt_330,
      O => Result(13)
    );
  Mcount_contador_cy_14_Q : MUXCY
    port map (
      CI => Mcount_contador_cy(13),
      DI => led_2_OBUF_103,
      S => Mcount_contador_cy_14_rt_331,
      O => Mcount_contador_cy(14)
    );
  Mcount_contador_xor_14_Q : XORCY
    port map (
      CI => Mcount_contador_cy(13),
      LI => Mcount_contador_cy_14_rt_331,
      O => Result(14)
    );
  Mcount_contador_cy_15_Q : MUXCY
    port map (
      CI => Mcount_contador_cy(14),
      DI => led_2_OBUF_103,
      S => Mcount_contador_cy_15_rt_332,
      O => Mcount_contador_cy(15)
    );
  Mcount_contador_xor_15_Q : XORCY
    port map (
      CI => Mcount_contador_cy(14),
      LI => Mcount_contador_cy_15_rt_332,
      O => Result(15)
    );
  Mcount_contador_cy_16_Q : MUXCY
    port map (
      CI => Mcount_contador_cy(15),
      DI => led_2_OBUF_103,
      S => Mcount_contador_cy_16_rt_333,
      O => Mcount_contador_cy(16)
    );
  Mcount_contador_xor_16_Q : XORCY
    port map (
      CI => Mcount_contador_cy(15),
      LI => Mcount_contador_cy_16_rt_333,
      O => Result(16)
    );
  Mcount_contador_cy_17_Q : MUXCY
    port map (
      CI => Mcount_contador_cy(16),
      DI => led_2_OBUF_103,
      S => Mcount_contador_cy_17_rt_334,
      O => Mcount_contador_cy(17)
    );
  Mcount_contador_xor_17_Q : XORCY
    port map (
      CI => Mcount_contador_cy(16),
      LI => Mcount_contador_cy_17_rt_334,
      O => Result(17)
    );
  Mcount_contador_cy_18_Q : MUXCY
    port map (
      CI => Mcount_contador_cy(17),
      DI => led_2_OBUF_103,
      S => Mcount_contador_cy_18_rt_335,
      O => Mcount_contador_cy(18)
    );
  Mcount_contador_xor_18_Q : XORCY
    port map (
      CI => Mcount_contador_cy(17),
      LI => Mcount_contador_cy_18_rt_335,
      O => Result(18)
    );
  Mcount_contador_cy_19_Q : MUXCY
    port map (
      CI => Mcount_contador_cy(18),
      DI => led_2_OBUF_103,
      S => Mcount_contador_cy_19_rt_336,
      O => Mcount_contador_cy(19)
    );
  Mcount_contador_xor_19_Q : XORCY
    port map (
      CI => Mcount_contador_cy(18),
      LI => Mcount_contador_cy_19_rt_336,
      O => Result(19)
    );
  Mcount_contador_xor_20_Q : XORCY
    port map (
      CI => Mcount_contador_cy(19),
      LI => Mcount_contador_xor_20_rt_338,
      O => Result(20)
    );
  Mcount_segundo_tick_cy_0_Q : MUXCY
    port map (
      CI => N0,
      DI => led_2_OBUF_103,
      S => Mcount_segundo_tick_cy_0_rt_337,
      O => Mcount_segundo_tick_cy(0)
    );
  Mcount_segundo_tick_xor_0_Q : XORCY
    port map (
      CI => N0,
      LI => Mcount_segundo_tick_cy_0_rt_337,
      O => Result_0_1
    );
  Mcount_segundo_tick_cy_1_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(0),
      DI => N0,
      S => Mcount_segundo_tick_lut(1),
      O => Mcount_segundo_tick_cy(1)
    );
  Mcount_segundo_tick_xor_1_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(0),
      LI => Mcount_segundo_tick_lut(1),
      O => Result_1_1
    );
  Mcount_segundo_tick_cy_2_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(1),
      DI => N0,
      S => Mcount_segundo_tick_lut(2),
      O => Mcount_segundo_tick_cy(2)
    );
  Mcount_segundo_tick_xor_2_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(1),
      LI => Mcount_segundo_tick_lut(2),
      O => Result_2_1
    );
  Mcount_segundo_tick_cy_3_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(2),
      DI => N0,
      S => Mcount_segundo_tick_lut(3),
      O => Mcount_segundo_tick_cy(3)
    );
  Mcount_segundo_tick_xor_3_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(2),
      LI => Mcount_segundo_tick_lut(3),
      O => Result_3_1
    );
  Mcount_segundo_tick_cy_4_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(3),
      DI => N0,
      S => Mcount_segundo_tick_lut(4),
      O => Mcount_segundo_tick_cy(4)
    );
  Mcount_segundo_tick_xor_4_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(3),
      LI => Mcount_segundo_tick_lut(4),
      O => Result_4_1
    );
  Mcount_segundo_tick_cy_5_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(4),
      DI => N0,
      S => Mcount_segundo_tick_lut(5),
      O => Mcount_segundo_tick_cy(5)
    );
  Mcount_segundo_tick_xor_5_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(4),
      LI => Mcount_segundo_tick_lut(5),
      O => Result_5_1
    );
  Mcount_segundo_tick_cy_6_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(5),
      DI => N0,
      S => Mcount_segundo_tick_lut(6),
      O => Mcount_segundo_tick_cy(6)
    );
  Mcount_segundo_tick_xor_6_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(5),
      LI => Mcount_segundo_tick_lut(6),
      O => Result_6_1
    );
  Mcount_segundo_tick_cy_7_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(6),
      DI => N0,
      S => Mcount_segundo_tick_lut(7),
      O => Mcount_segundo_tick_cy(7)
    );
  Mcount_segundo_tick_xor_7_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(6),
      LI => Mcount_segundo_tick_lut(7),
      O => Result_7_1
    );
  Mcount_segundo_tick_cy_8_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(7),
      DI => N0,
      S => Mcount_segundo_tick_lut(8),
      O => Mcount_segundo_tick_cy(8)
    );
  Mcount_segundo_tick_xor_8_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(7),
      LI => Mcount_segundo_tick_lut(8),
      O => Result_8_1
    );
  Mcount_segundo_tick_cy_9_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(8),
      DI => N0,
      S => Mcount_segundo_tick_lut(9),
      O => Mcount_segundo_tick_cy(9)
    );
  Mcount_segundo_tick_xor_9_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(8),
      LI => Mcount_segundo_tick_lut(9),
      O => Result_9_1
    );
  Mcount_segundo_tick_cy_10_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(9),
      DI => N0,
      S => Mcount_segundo_tick_lut(10),
      O => Mcount_segundo_tick_cy(10)
    );
  Mcount_segundo_tick_xor_10_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(9),
      LI => Mcount_segundo_tick_lut(10),
      O => Result_10_1
    );
  Mcount_segundo_tick_cy_11_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(10),
      DI => N0,
      S => Mcount_segundo_tick_lut(11),
      O => Mcount_segundo_tick_cy(11)
    );
  Mcount_segundo_tick_xor_11_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(10),
      LI => Mcount_segundo_tick_lut(11),
      O => Result_11_1
    );
  Mcount_segundo_tick_cy_12_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(11),
      DI => N0,
      S => Mcount_segundo_tick_lut(12),
      O => Mcount_segundo_tick_cy(12)
    );
  Mcount_segundo_tick_xor_12_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(11),
      LI => Mcount_segundo_tick_lut(12),
      O => Result_12_1
    );
  Mcount_segundo_tick_cy_13_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(12),
      DI => N0,
      S => Mcount_segundo_tick_lut(13),
      O => Mcount_segundo_tick_cy(13)
    );
  Mcount_segundo_tick_xor_13_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(12),
      LI => Mcount_segundo_tick_lut(13),
      O => Result_13_1
    );
  Mcount_segundo_tick_cy_14_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(13),
      DI => N0,
      S => Mcount_segundo_tick_lut(14),
      O => Mcount_segundo_tick_cy(14)
    );
  Mcount_segundo_tick_xor_14_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(13),
      LI => Mcount_segundo_tick_lut(14),
      O => Result_14_1
    );
  Mcount_segundo_tick_cy_15_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(14),
      DI => N0,
      S => Mcount_segundo_tick_lut(15),
      O => Mcount_segundo_tick_cy(15)
    );
  Mcount_segundo_tick_xor_15_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(14),
      LI => Mcount_segundo_tick_lut(15),
      O => Result_15_1
    );
  Mcount_segundo_tick_cy_16_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(15),
      DI => N0,
      S => Mcount_segundo_tick_lut(16),
      O => Mcount_segundo_tick_cy(16)
    );
  Mcount_segundo_tick_xor_16_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(15),
      LI => Mcount_segundo_tick_lut(16),
      O => Result_16_1
    );
  Mcount_segundo_tick_cy_17_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(16),
      DI => N0,
      S => Mcount_segundo_tick_lut(17),
      O => Mcount_segundo_tick_cy(17)
    );
  Mcount_segundo_tick_xor_17_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(16),
      LI => Mcount_segundo_tick_lut(17),
      O => Result_17_1
    );
  Mcount_segundo_tick_cy_18_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(17),
      DI => N0,
      S => Mcount_segundo_tick_lut(18),
      O => Mcount_segundo_tick_cy(18)
    );
  Mcount_segundo_tick_xor_18_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(17),
      LI => Mcount_segundo_tick_lut(18),
      O => Result_18_1
    );
  Mcount_segundo_tick_cy_19_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(18),
      DI => N0,
      S => Mcount_segundo_tick_lut(19),
      O => Mcount_segundo_tick_cy(19)
    );
  Mcount_segundo_tick_xor_19_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(18),
      LI => Mcount_segundo_tick_lut(19),
      O => Result_19_1
    );
  Mcount_segundo_tick_cy_20_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(19),
      DI => N0,
      S => Mcount_segundo_tick_lut(20),
      O => Mcount_segundo_tick_cy(20)
    );
  Mcount_segundo_tick_xor_20_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(19),
      LI => Mcount_segundo_tick_lut(20),
      O => Result_20_1
    );
  Mcount_segundo_tick_cy_21_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(20),
      DI => N0,
      S => Mcount_segundo_tick_lut(21),
      O => Mcount_segundo_tick_cy(21)
    );
  Mcount_segundo_tick_xor_21_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(20),
      LI => Mcount_segundo_tick_lut(21),
      O => Result(21)
    );
  Mcount_segundo_tick_cy_22_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(21),
      DI => N0,
      S => Mcount_segundo_tick_lut(22),
      O => Mcount_segundo_tick_cy(22)
    );
  Mcount_segundo_tick_xor_22_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(21),
      LI => Mcount_segundo_tick_lut(22),
      O => Result(22)
    );
  Mcount_segundo_tick_cy_23_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(22),
      DI => N0,
      S => Mcount_segundo_tick_lut(23),
      O => Mcount_segundo_tick_cy(23)
    );
  Mcount_segundo_tick_xor_23_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(22),
      LI => Mcount_segundo_tick_lut(23),
      O => Result(23)
    );
  Mcount_segundo_tick_cy_24_Q : MUXCY
    port map (
      CI => Mcount_segundo_tick_cy(23),
      DI => N0,
      S => Mcount_segundo_tick_lut(24),
      O => Mcount_segundo_tick_cy(24)
    );
  Mcount_segundo_tick_xor_24_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(23),
      LI => Mcount_segundo_tick_lut(24),
      O => Result(24)
    );
  Mcount_segundo_tick_xor_25_Q : XORCY
    port map (
      CI => Mcount_segundo_tick_cy(24),
      LI => Mcount_segundo_tick_lut(25),
      O => Result(25)
    );
  anodo_3_1 : LUT2
    generic map(
      INIT => X"7"
    )
    port map (
      I0 => contador(16),
      I1 => contador(17),
      O => anodo_3_OBUF_89
    );
  anodo_2_1 : LUT2
    generic map(
      INIT => X"D"
    )
    port map (
      I0 => contador(17),
      I1 => contador(16),
      O => anodo_2_OBUF_90
    );
  anodo_1_1 : LUT2
    generic map(
      INIT => X"D"
    )
    port map (
      I0 => contador(16),
      I1 => contador(17),
      O => anodo_1_OBUF_91
    );
  anodo_0_1 : LUT2
    generic map(
      INIT => X"E"
    )
    port map (
      I0 => contador(16),
      I1 => contador(17),
      O => anodo_0_OBUF_92
    );
  Q_n0332_inv1 : LUT3
    generic map(
      INIT => X"40"
    )
    port map (
      I0 => btnAlarma_registro(1),
      I1 => btnAlarma_registro(0),
      I2 => contador_20_GND_4_o_equal_28_o,
      O => Q_n0332_inv
    );
  Mmux_hora_bajo_3_hora_bajo_3_mux_92_OUT21 : LUT3
    generic map(
      INIT => X"28"
    )
    port map (
      I0 => Mmux_hora_bajo_3_hora_bajo_3_mux_92_OUT11,
      I1 => hora_bajo(0),
      I2 => hora_bajo(1),
      O => hora_bajo_3_hora_bajo_3_mux_92_OUT_1_Q
    );
  min_bajo_3_PWR_4_o_equal_86_o_3_1 : LUT4
    generic map(
      INIT => X"0020"
    )
    port map (
      I0 => min_bajo(3),
      I1 => min_bajo(2),
      I2 => min_bajo(1),
      I3 => min_bajo(0),
      O => min_bajo_3_PWR_4_o_equal_86_o_inv_inv
    );
  contador_diez_segundos_3_PWR_4_o_equal_76_o_3_1 : LUT4
    generic map(
      INIT => X"0020"
    )
    port map (
      I0 => contador_diez_segundos(3),
      I1 => contador_diez_segundos(2),
      I2 => contador_diez_segundos(1),
      I3 => puntos_index(0),
      O => contador_diez_segundos_3_PWR_4_o_equal_76_o_inv_inv
    );
  Mcount_segundo_tick_eqn_251 : LUT2
    generic map(
      INIT => X"E"
    )
    port map (
      I0 => segundo_tick_25_GND_4_o_equal_13_o,
      I1 => Result(25),
      O => Mcount_segundo_tick_eqn_25
    );
  Mcount_segundo_tick_eqn_231 : LUT2
    generic map(
      INIT => X"E"
    )
    port map (
      I0 => segundo_tick_25_GND_4_o_equal_13_o,
      I1 => Result(23),
      O => Mcount_segundo_tick_eqn_23
    );
  Mcount_segundo_tick_eqn_221 : LUT2
    generic map(
      INIT => X"E"
    )
    port map (
      I0 => segundo_tick_25_GND_4_o_equal_13_o,
      I1 => Result(22),
      O => Mcount_segundo_tick_eqn_22
    );
  Mcount_segundo_tick_eqn_211 : LUT2
    generic map(
      INIT => X"E"
    )
    port map (
      I0 => segundo_tick_25_GND_4_o_equal_13_o,
      I1 => Result(21),
      O => Mcount_segundo_tick_eqn_21
    );
  Mcount_segundo_tick_eqn_201 : LUT2
    generic map(
      INIT => X"E"
    )
    port map (
      I0 => segundo_tick_25_GND_4_o_equal_13_o,
      I1 => Result_20_1,
      O => Mcount_segundo_tick_eqn_20
    );
  Mcount_segundo_tick_eqn_191 : LUT2
    generic map(
      INIT => X"E"
    )
    port map (
      I0 => Result_19_1,
      I1 => segundo_tick_25_GND_4_o_equal_13_o,
      O => Mcount_segundo_tick_eqn_19
    );
  Q_n0324_inv1 : LUT2
    generic map(
      INIT => X"4"
    )
    port map (
      I0 => stop_IBUF_1,
      I1 => segundo_tick_25_GND_4_o_equal_13_o,
      O => Q_n0324_inv
    );
  contador_diez_unidades_2_PWR_4_o_equal_81_o_2_1 : LUT3
    generic map(
      INIT => X"20"
    )
    port map (
      I0 => contador_diez_unidades(1),
      I1 => contador_diez_unidades(0),
      I2 => contador_diez_unidades(2),
      O => contador_diez_unidades_2_PWR_4_o_equal_81_o
    );
  Mcount_puntos_index21 : LUT5
    generic map(
      INIT => X"6A6A2A6A"
    )
    port map (
      I0 => puntos_index(2),
      I1 => puntos_index(0),
      I2 => puntos_index(1),
      I3 => puntos_index(4),
      I4 => puntos_index(3),
      O => Mcount_puntos_index2
    );
  Mcount_puntos_index31 : LUT4
    generic map(
      INIT => X"6CCC"
    )
    port map (
      I0 => puntos_index(2),
      I1 => puntos_index(3),
      I2 => puntos_index(0),
      I3 => puntos_index(1),
      O => Mcount_puntos_index3
    );
  Mcount_puntos_index41 : LUT5
    generic map(
      INIT => X"6AAAAA2A"
    )
    port map (
      I0 => puntos_index(4),
      I1 => puntos_index(0),
      I2 => puntos_index(1),
      I3 => puntos_index(2),
      I4 => puntos_index(3),
      O => Mcount_puntos_index4
    );
  Mcount_puntos_index11 : LUT2
    generic map(
      INIT => X"6"
    )
    port map (
      I0 => puntos_index(0),
      I1 => puntos_index(1),
      O => Mcount_puntos_index1
    );
  Mram_segmento_6_0_51 : LUT4
    generic map(
      INIT => X"4054"
    )
    port map (
      I0 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_3_Q,
      I1 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_0_Q,
      I2 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_1_Q,
      I3 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_2_Q,
      O => segmento_5_OBUF_96
    );
  Mmux_contador_17_segmento_digitos_3_6_wide_mux_8_OUT_0_11 : LUT6
    generic map(
      INIT => X"FD75B931EC64A820"
    )
    port map (
      I0 => contador(16),
      I1 => contador(17),
      I2 => min_alto(0),
      I3 => hora_alto(0),
      I4 => hora_bajo(0),
      I5 => min_bajo(0),
      O => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_0_Q
    );
  Mram_segmento_6_0_61 : LUT4
    generic map(
      INIT => X"4101"
    )
    port map (
      I0 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_3_Q,
      I1 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_1_Q,
      I2 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_2_Q,
      I3 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_0_Q,
      O => segmento_6_OBUF_95
    );
  Mmux_contador_17_segmento_digitos_3_6_wide_mux_8_OUT_3_11 : LUT4
    generic map(
      INIT => X"5410"
    )
    port map (
      I0 => contador(16),
      I1 => contador(17),
      I2 => min_bajo(3),
      I3 => hora_bajo(3),
      O => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_3_Q
    );
  Mram_segmento_6_0_12 : LUT4
    generic map(
      INIT => X"0110"
    )
    port map (
      I0 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_1_Q,
      I1 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_3_Q,
      I2 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_0_Q,
      I3 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_2_Q,
      O => segmento_0_OBUF_101
    );
  Mmux_contador_17_segmento_digitos_3_6_wide_mux_8_OUT_1_11 : LUT6
    generic map(
      INIT => X"FD75B931EC64A820"
    )
    port map (
      I0 => contador(16),
      I1 => contador(17),
      I2 => min_alto(1),
      I3 => hora_alto(1),
      I4 => hora_bajo(1),
      I5 => min_bajo(1),
      O => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_1_Q
    );
  Mmux_contador_17_segmento_digitos_3_6_wide_mux_8_OUT_2_11 : LUT5
    generic map(
      INIT => X"73625140"
    )
    port map (
      I0 => contador(17),
      I1 => contador(16),
      I2 => min_alto(2),
      I3 => min_bajo(2),
      I4 => hora_bajo(2),
      O => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_2_Q
    );
  Mram_segmento_6_0_21 : LUT4
    generic map(
      INIT => X"0004"
    )
    port map (
      I0 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_2_Q,
      I1 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_1_Q,
      I2 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_3_Q,
      I3 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_0_Q,
      O => segmento_2_OBUF_99
    );
  Reset_OR_DriverANDClockEnable1 : LUT6
    generic map(
      INIT => X"0400041004000400"
    )
    port map (
      I0 => hora_bajo(0),
      I1 => hora_bajo(1),
      I2 => hora_bajo(2),
      I3 => hora_bajo(3),
      I4 => hora_alto(0),
      I5 => hora_alto(1),
      O => Reset_OR_DriverANDClockEnable
    );
  Q_n02981 : LUT3
    generic map(
      INIT => X"40"
    )
    port map (
      I0 => btnRst_registro(1),
      I1 => btnRst_registro(0),
      I2 => contador_20_GND_4_o_equal_28_o,
      O => Q_n0298
    );
  Mram_segmento_6_0_41 : LUT4
    generic map(
      INIT => X"AAAE"
    )
    port map (
      I0 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_0_Q,
      I1 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_2_Q,
      I2 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_1_Q,
      I3 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_3_Q,
      O => segmento_4_OBUF_97
    );
  Mram_segmento_6_0_31 : LUT4
    generic map(
      INIT => X"A98A"
    )
    port map (
      I0 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_0_Q,
      I1 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_3_Q,
      I2 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_1_Q,
      I3 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_2_Q,
      O => segmento_3_OBUF_98
    );
  Mram_segmento_6_0_111 : LUT4
    generic map(
      INIT => X"0220"
    )
    port map (
      I0 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_2_Q,
      I1 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_3_Q,
      I2 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_0_Q,
      I3 => contador_17_segmento_digitos_3_6_wide_mux_8_OUT_1_Q,
      O => segmento_1_OBUF_100
    );
  Mmux_hora_bajo_3_hora_bajo_3_mux_92_OUT111 : LUT5
    generic map(
      INIT => X"FF08FFFF"
    )
    port map (
      I0 => min_alto(1),
      I1 => min_alto(2),
      I2 => min_alto(0),
      I3 => btnRst_registro(1),
      I4 => btnRst_registro(0),
      O => Mmux_hora_bajo_3_hora_bajo_3_mux_92_OUT11
    );
  Mmux_hora_bajo_3_hora_bajo_3_mux_92_OUT31 : LUT4
    generic map(
      INIT => X"2888"
    )
    port map (
      I0 => Mmux_hora_bajo_3_hora_bajo_3_mux_92_OUT11,
      I1 => hora_bajo(2),
      I2 => hora_bajo(0),
      I3 => hora_bajo(1),
      O => hora_bajo_3_hora_bajo_3_mux_92_OUT_2_Q
    );
  Mmux_hora_bajo_3_hora_bajo_3_mux_92_OUT41 : LUT5
    generic map(
      INIT => X"28888888"
    )
    port map (
      I0 => Mmux_hora_bajo_3_hora_bajo_3_mux_92_OUT11,
      I1 => hora_bajo(3),
      I2 => hora_bajo(0),
      I3 => hora_bajo(1),
      I4 => hora_bajo(2),
      O => hora_bajo_3_hora_bajo_3_mux_92_OUT_3_Q
    );
  Mcount_hora_alto_xor_1_11 : LUT6
    generic map(
      INIT => X"A9AAAAAAAAAAAAAA"
    )
    port map (
      I0 => hora_alto(1),
      I1 => hora_bajo(2),
      I2 => hora_bajo(0),
      I3 => hora_alto(0),
      I4 => hora_bajo(3),
      I5 => hora_bajo(1),
      O => Mcount_hora_alto1
    );
  alarma1 : LUT6
    generic map(
      INIT => X"9009000000009009"
    )
    port map (
      I0 => hb_alarma(2),
      I1 => hora_bajo(2),
      I2 => hb_alarma(1),
      I3 => hora_bajo(1),
      I4 => hb_alarma(0),
      I5 => hora_bajo(0),
      O => alarma1_277
    );
  alarma2 : LUT6
    generic map(
      INIT => X"9009000000009009"
    )
    port map (
      I0 => mb_alarma(2),
      I1 => min_bajo(2),
      I2 => mb_alarma(0),
      I3 => min_bajo(0),
      I4 => ma_alarma(2),
      I5 => min_alto(2),
      O => alarma2_278
    );
  alarma3 : LUT6
    generic map(
      INIT => X"9009000000009009"
    )
    port map (
      I0 => hb_alarma(3),
      I1 => hora_bajo(3),
      I2 => mb_alarma(1),
      I3 => min_bajo(1),
      I4 => mb_alarma(3),
      I5 => min_bajo(3),
      O => alarma3_279
    );
  alarma4 : LUT6
    generic map(
      INIT => X"9009000000009009"
    )
    port map (
      I0 => ha_alarma(1),
      I1 => hora_alto(1),
      I2 => ma_alarma(1),
      I3 => min_alto(1),
      I4 => ma_alarma(0),
      I5 => min_alto(0),
      O => alarma4_280
    );
  alarma5 : LUT6
    generic map(
      INIT => X"8000000000008000"
    )
    port map (
      I0 => alarma3_279,
      I1 => alarma4_280,
      I2 => alarma1_277,
      I3 => alarma2_278,
      I4 => ha_alarma(0),
      I5 => hora_alto(0),
      O => alarma_OBUF_84
    );
  segundo_tick_25_GND_4_o_equal_13_o_25_1 : LUT6
    generic map(
      INIT => X"0000000000000001"
    )
    port map (
      I0 => segundo_tick(1),
      I1 => segundo_tick(0),
      I2 => segundo_tick(2),
      I3 => segundo_tick(3),
      I4 => segundo_tick(4),
      I5 => segundo_tick(5),
      O => segundo_tick_25_GND_4_o_equal_13_o_25_Q
    );
  segundo_tick_25_GND_4_o_equal_13_o_25_2 : LUT6
    generic map(
      INIT => X"0000000000000001"
    )
    port map (
      I0 => segundo_tick(7),
      I1 => segundo_tick(6),
      I2 => segundo_tick(8),
      I3 => segundo_tick(9),
      I4 => segundo_tick(10),
      I5 => segundo_tick(11),
      O => segundo_tick_25_GND_4_o_equal_13_o_25_1_282
    );
  segundo_tick_25_GND_4_o_equal_13_o_25_3 : LUT6
    generic map(
      INIT => X"0000000000000001"
    )
    port map (
      I0 => segundo_tick(13),
      I1 => segundo_tick(12),
      I2 => segundo_tick(14),
      I3 => segundo_tick(15),
      I4 => segundo_tick(16),
      I5 => segundo_tick(17),
      O => segundo_tick_25_GND_4_o_equal_13_o_25_2_283
    );
  segundo_tick_25_GND_4_o_equal_13_o_25_4 : LUT6
    generic map(
      INIT => X"0000000000000001"
    )
    port map (
      I0 => segundo_tick(19),
      I1 => segundo_tick(18),
      I2 => segundo_tick(20),
      I3 => segundo_tick(21),
      I4 => segundo_tick(22),
      I5 => segundo_tick(23),
      O => segundo_tick_25_GND_4_o_equal_13_o_25_3_284
    );
  segundo_tick_25_GND_4_o_equal_13_o_25_5 : LUT6
    generic map(
      INIT => X"1000000000000000"
    )
    port map (
      I0 => segundo_tick(24),
      I1 => segundo_tick(25),
      I2 => segundo_tick_25_GND_4_o_equal_13_o_25_3_284,
      I3 => segundo_tick_25_GND_4_o_equal_13_o_25_2_283,
      I4 => segundo_tick_25_GND_4_o_equal_13_o_25_1_282,
      I5 => segundo_tick_25_GND_4_o_equal_13_o_25_Q,
      O => segundo_tick_25_GND_4_o_equal_13_o
    );
  contador_20_GND_4_o_equal_28_o_20_1 : LUT6
    generic map(
      INIT => X"0000000000000001"
    )
    port map (
      I0 => contador(1),
      I1 => contador(0),
      I2 => contador(2),
      I3 => contador(3),
      I4 => contador(4),
      I5 => contador(5),
      O => contador_20_GND_4_o_equal_28_o_20_Q
    );
  contador_20_GND_4_o_equal_28_o_20_2 : LUT6
    generic map(
      INIT => X"0000000000000001"
    )
    port map (
      I0 => contador(7),
      I1 => contador(6),
      I2 => contador(8),
      I3 => contador(9),
      I4 => contador(10),
      I5 => contador(11),
      O => contador_20_GND_4_o_equal_28_o_20_1_286
    );
  contador_20_GND_4_o_equal_28_o_20_3 : LUT6
    generic map(
      INIT => X"0000000000000001"
    )
    port map (
      I0 => contador(13),
      I1 => contador(12),
      I2 => contador(14),
      I3 => contador(15),
      I4 => contador(16),
      I5 => contador(17),
      O => contador_20_GND_4_o_equal_28_o_20_2_287
    );
  contador_20_GND_4_o_equal_28_o_20_4 : LUT6
    generic map(
      INIT => X"0100000000000000"
    )
    port map (
      I0 => contador(20),
      I1 => contador(18),
      I2 => contador(19),
      I3 => contador_20_GND_4_o_equal_28_o_20_2_287,
      I4 => contador_20_GND_4_o_equal_28_o_20_1_286,
      I5 => contador_20_GND_4_o_equal_28_o_20_Q,
      O => contador_20_GND_4_o_equal_28_o
    );
  Mcount_hora_alto_val_SW0 : LUT2
    generic map(
      INIT => X"D"
    )
    port map (
      I0 => hora_alto(1),
      I1 => hora_alto(0),
      O => N5
    );
  Q_n0367_inv11 : LUT4
    generic map(
      INIT => X"0020"
    )
    port map (
      I0 => hora_bajo(3),
      I1 => hora_bajo(2),
      I2 => hora_bajo(1),
      I3 => hora_bajo(0),
      O => Q_n0367_inv11_289
    );
  Q_n0367_inv12 : LUT4
    generic map(
      INIT => X"22F2"
    )
    port map (
      I0 => btnIzq_registro(0),
      I1 => btnIzq_registro(1),
      I2 => btnRst_registro(0),
      I3 => btnRst_registro(1),
      O => Q_n0367_inv12_290
    );
  Q_n0367_inv13 : LUT6
    generic map(
      INIT => X"FFFFFF08FFFF0808"
    )
    port map (
      I0 => min_alto(2),
      I1 => min_alto(1),
      I2 => min_alto(0),
      I3 => Q_n0367_inv12_290,
      I4 => Q_n0367_inv11_289,
      I5 => contador_20_GND_4_o_equal_28_o,
      O => Q_n0367_inv1
    );
  stop_IBUF : IBUF
    port map (
      I => stop,
      O => stop_IBUF_1
    );
  btnIzq_IBUF : IBUF
    port map (
      I => btnIzq,
      O => btnIzq_IBUF_2
    );
  btnDer_IBUF : IBUF
    port map (
      I => btnDer,
      O => btnDer_IBUF_3
    );
  btnRst_IBUF : IBUF
    port map (
      I => btnRst,
      O => btnRst_IBUF_4
    );
  btnAlarma_IBUF : IBUF
    port map (
      I => btnAlarma,
      O => btnAlarma_IBUF_5
    );
  segmento_7_OBUF : OBUF
    port map (
      I => segmento_7_OBUF_82,
      O => segmento(7)
    );
  segmento_6_OBUF : OBUF
    port map (
      I => segmento_6_OBUF_95,
      O => segmento(6)
    );
  segmento_5_OBUF : OBUF
    port map (
      I => segmento_5_OBUF_96,
      O => segmento(5)
    );
  segmento_4_OBUF : OBUF
    port map (
      I => segmento_4_OBUF_97,
      O => segmento(4)
    );
  segmento_3_OBUF : OBUF
    port map (
      I => segmento_3_OBUF_98,
      O => segmento(3)
    );
  segmento_2_OBUF : OBUF
    port map (
      I => segmento_2_OBUF_99,
      O => segmento(2)
    );
  segmento_1_OBUF : OBUF
    port map (
      I => segmento_1_OBUF_100,
      O => segmento(1)
    );
  segmento_0_OBUF : OBUF
    port map (
      I => segmento_0_OBUF_101,
      O => segmento(0)
    );
  anodo_3_OBUF : OBUF
    port map (
      I => anodo_3_OBUF_89,
      O => anodo(3)
    );
  anodo_2_OBUF : OBUF
    port map (
      I => anodo_2_OBUF_90,
      O => anodo(2)
    );
  anodo_1_OBUF : OBUF
    port map (
      I => anodo_1_OBUF_91,
      O => anodo(1)
    );
  anodo_0_OBUF : OBUF
    port map (
      I => anodo_0_OBUF_92,
      O => anodo(0)
    );
  led_7_OBUF : OBUF
    port map (
      I => led_registro(4),
      O => led(7)
    );
  led_6_OBUF : OBUF
    port map (
      I => led_registro(3),
      O => led(6)
    );
  led_5_OBUF : OBUF
    port map (
      I => led_registro(2),
      O => led(5)
    );
  led_4_OBUF : OBUF
    port map (
      I => led_registro(1),
      O => led(4)
    );
  led_3_OBUF : OBUF
    port map (
      I => led_registro(0),
      O => led(3)
    );
  led_2_OBUF : OBUF
    port map (
      I => led_2_OBUF_103,
      O => led(2)
    );
  led_1_OBUF : OBUF
    port map (
      I => led_0_inv,
      O => led(1)
    );
  led_0_OBUF : OBUF
    port map (
      I => pendulo(0),
      O => led(0)
    );
  alarma_OBUF : OBUF
    port map (
      I => alarma_OBUF_84,
      O => alarma
    );
  Mcount_contador_cy_1_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => contador(1),
      O => Mcount_contador_cy_1_rt_318
    );
  Mcount_contador_cy_2_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => contador(2),
      O => Mcount_contador_cy_2_rt_319
    );
  Mcount_contador_cy_3_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => contador(3),
      O => Mcount_contador_cy_3_rt_320
    );
  Mcount_contador_cy_4_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => contador(4),
      O => Mcount_contador_cy_4_rt_321
    );
  Mcount_contador_cy_5_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => contador(5),
      O => Mcount_contador_cy_5_rt_322
    );
  Mcount_contador_cy_6_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => contador(6),
      O => Mcount_contador_cy_6_rt_323
    );
  Mcount_contador_cy_7_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => contador(7),
      O => Mcount_contador_cy_7_rt_324
    );
  Mcount_contador_cy_8_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => contador(8),
      O => Mcount_contador_cy_8_rt_325
    );
  Mcount_contador_cy_9_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => contador(9),
      O => Mcount_contador_cy_9_rt_326
    );
  Mcount_contador_cy_10_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => contador(10),
      O => Mcount_contador_cy_10_rt_327
    );
  Mcount_contador_cy_11_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => contador(11),
      O => Mcount_contador_cy_11_rt_328
    );
  Mcount_contador_cy_12_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => contador(12),
      O => Mcount_contador_cy_12_rt_329
    );
  Mcount_contador_cy_13_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => contador(13),
      O => Mcount_contador_cy_13_rt_330
    );
  Mcount_contador_cy_14_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => contador(14),
      O => Mcount_contador_cy_14_rt_331
    );
  Mcount_contador_cy_15_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => contador(15),
      O => Mcount_contador_cy_15_rt_332
    );
  Mcount_contador_cy_16_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => contador(16),
      O => Mcount_contador_cy_16_rt_333
    );
  Mcount_contador_cy_17_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => contador(17),
      O => Mcount_contador_cy_17_rt_334
    );
  Mcount_contador_cy_18_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => contador(18),
      O => Mcount_contador_cy_18_rt_335
    );
  Mcount_contador_cy_19_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => contador(19),
      O => Mcount_contador_cy_19_rt_336
    );
  Mcount_segundo_tick_cy_0_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => segundo_tick(0),
      O => Mcount_segundo_tick_cy_0_rt_337
    );
  Mcount_contador_xor_20_rt : LUT1
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => contador(20),
      O => Mcount_contador_xor_20_rt_338
    );
  pendulo_0 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk_BUFGP_0,
      D => pendulo_0_rstpot_339,
      Q => pendulo(0)
    );
  Mcount_min_bajo_val1 : LUT5
    generic map(
      INIT => X"FF04FF00"
    )
    port map (
      I0 => btnRst_registro(1),
      I1 => btnRst_registro(0),
      I2 => contador_diez_unidades_2_PWR_4_o_equal_81_o,
      I3 => min_bajo_3_PWR_4_o_equal_86_o_inv_inv,
      I4 => contador_20_GND_4_o_equal_28_o,
      O => Mcount_min_bajo_val
    );
  Mcount_contador_diez_segundos_val1 : LUT4
    generic map(
      INIT => X"F4F0"
    )
    port map (
      I0 => btnRst_registro(1),
      I1 => btnRst_registro(0),
      I2 => contador_diez_segundos_3_PWR_4_o_equal_76_o_inv_inv,
      I3 => contador_20_GND_4_o_equal_28_o,
      O => Mcount_contador_diez_segundos_val
    );
  Mcount_contador_diez_unidades_val1 : LUT5
    generic map(
      INIT => X"F0F4F0F0"
    )
    port map (
      I0 => btnRst_registro(1),
      I1 => btnRst_registro(0),
      I2 => contador_diez_unidades_2_PWR_4_o_equal_81_o,
      I3 => contador_diez_segundos_3_PWR_4_o_equal_76_o_inv_inv,
      I4 => contador_20_GND_4_o_equal_28_o,
      O => Mcount_contador_diez_unidades_val
    );
  Reset_OR_DriverANDClockEnable11 : LUT5
    generic map(
      INIT => X"75553000"
    )
    port map (
      I0 => stop_IBUF_1,
      I1 => btnRst_registro(1),
      I2 => btnRst_registro(0),
      I3 => contador_20_GND_4_o_equal_28_o,
      I4 => segundo_tick_25_GND_4_o_equal_13_o,
      O => Reset_OR_DriverANDClockEnable1_185
    );
  Q_n02981_SW0 : LUT2
    generic map(
      INIT => X"D"
    )
    port map (
      I0 => min_alto(1),
      I1 => min_alto(0),
      O => N7
    );
  Mcount_min_alto_val1 : LUT6
    generic map(
      INIT => X"00AA30BA00AA00AA"
    )
    port map (
      I0 => min_alto(2),
      I1 => btnRst_registro(1),
      I2 => btnRst_registro(0),
      I3 => N7,
      I4 => min_bajo_3_PWR_4_o_equal_86_o_inv_inv,
      I5 => contador_20_GND_4_o_equal_28_o,
      O => Mcount_min_alto_val
    );
  Q_n02981_SW1 : LUT4
    generic map(
      INIT => X"FFFD"
    )
    port map (
      I0 => hora_bajo(2),
      I1 => hora_bajo(3),
      I2 => hora_bajo(1),
      I3 => hora_bajo(0),
      O => N9
    );
  Q_n02981_SW2 : LUT4
    generic map(
      INIT => X"FBFF"
    )
    port map (
      I0 => hora_bajo(0),
      I1 => hora_bajo(3),
      I2 => hora_bajo(2),
      I3 => hora_bajo(1),
      O => N10
    );
  Mcount_hora_alto_val : LUT6
    generic map(
      INIT => X"444F000B000F000F"
    )
    port map (
      I0 => btnRst_registro(1),
      I1 => btnRst_registro(0),
      I2 => N5,
      I3 => N9,
      I4 => N10,
      I5 => contador_20_GND_4_o_equal_28_o,
      O => Mcount_hora_alto_val_108
    );
  contador_diez_unidades_0 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => contador_diez_unidades_0_rstpot_343,
      Q => contador_diez_unidades(0)
    );
  contador_diez_unidades_1 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => contador_diez_unidades_1_rstpot_344,
      Q => contador_diez_unidades(1)
    );
  hora_alto_0 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => hora_alto_0_rstpot_345,
      Q => hora_alto(0)
    );
  hora_alto_1_rstpot : LUT2
    generic map(
      INIT => X"2"
    )
    port map (
      I0 => Mcount_hora_alto1,
      I1 => Mcount_hora_alto_val_108,
      O => hora_alto_1_rstpot_346
    );
  hora_alto_1 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => hora_alto_1_rstpot_346,
      Q => hora_alto(1)
    );
  segundo_tick_0 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => segundo_tick_0_rstpot_347,
      Q => segundo_tick(0)
    );
  segundo_tick_1 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => segundo_tick_1_rstpot_348,
      Q => segundo_tick(1)
    );
  segundo_tick_2 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => segundo_tick_2_rstpot_349,
      Q => segundo_tick(2)
    );
  contador_diez_unidades_2 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => contador_diez_unidades_2_rstpot_350,
      Q => contador_diez_unidades(2)
    );
  min_alto_0 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => min_alto_0_rstpot_351,
      Q => min_alto(0)
    );
  min_alto_1 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => min_alto_1_rstpot_352,
      Q => min_alto(1)
    );
  min_alto_2 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => min_alto_2_rstpot_353,
      Q => min_alto(2)
    );
  contador_diez_segundos_1 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => contador_diez_segundos_1_rstpot_354,
      Q => contador_diez_segundos(1)
    );
  contador_diez_segundos_2 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => contador_diez_segundos_2_rstpot_355,
      Q => contador_diez_segundos(2)
    );
  contador_diez_segundos_3 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => contador_diez_segundos_3_rstpot_356,
      Q => contador_diez_segundos(3)
    );
  min_bajo_1 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => min_bajo_1_rstpot_357,
      Q => min_bajo(1)
    );
  min_bajo_2 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => min_bajo_2_rstpot_358,
      Q => min_bajo(2)
    );
  min_bajo_3 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => min_bajo_3_rstpot_359,
      Q => min_bajo(3)
    );
  min_bajo_0 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => min_bajo_0_rstpot_360,
      Q => min_bajo(0)
    );
  segundo_tick_3 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => segundo_tick_3_rstpot_361,
      Q => segundo_tick(3)
    );
  segundo_tick_4 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => segundo_tick_4_rstpot_362,
      Q => segundo_tick(4)
    );
  segundo_tick_5 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => segundo_tick_5_rstpot_363,
      Q => segundo_tick(5)
    );
  segundo_tick_6 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => segundo_tick_6_rstpot_364,
      Q => segundo_tick(6)
    );
  segundo_tick_8 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => segundo_tick_8_rstpot_365,
      Q => segundo_tick(8)
    );
  segundo_tick_9 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => segundo_tick_9_rstpot_366,
      Q => segundo_tick(9)
    );
  segundo_tick_10 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => segundo_tick_10_rstpot_367,
      Q => segundo_tick(10)
    );
  segundo_tick_11 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => segundo_tick_11_rstpot_368,
      Q => segundo_tick(11)
    );
  contador_diez_segundos_3_rstpot : LUT6
    generic map(
      INIT => X"00006AAA0000AAAA"
    )
    port map (
      I0 => contador_diez_segundos(3),
      I1 => contador_diez_segundos(2),
      I2 => contador_diez_segundos(1),
      I3 => puntos_index(0),
      I4 => Mcount_contador_diez_segundos_val,
      I5 => Q_n0324_inv,
      O => contador_diez_segundos_3_rstpot_356
    );
  min_bajo_1_rstpot : LUT4
    generic map(
      INIT => X"006A"
    )
    port map (
      I0 => min_bajo(1),
      I1 => min_bajo(0),
      I2 => Q_n0359_inv,
      I3 => Mcount_min_bajo_val,
      O => min_bajo_1_rstpot_357
    );
  min_bajo_2_rstpot : LUT5
    generic map(
      INIT => X"00006AAA"
    )
    port map (
      I0 => min_bajo(2),
      I1 => min_bajo(1),
      I2 => min_bajo(0),
      I3 => Q_n0359_inv,
      I4 => Mcount_min_bajo_val,
      O => min_bajo_2_rstpot_358
    );
  min_bajo_3_rstpot : LUT6
    generic map(
      INIT => X"000000006AAAAAAA"
    )
    port map (
      I0 => min_bajo(3),
      I1 => min_bajo(2),
      I2 => min_bajo(1),
      I3 => min_bajo(0),
      I4 => Q_n0359_inv,
      I5 => Mcount_min_bajo_val,
      O => min_bajo_3_rstpot_359
    );
  min_bajo_0_rstpot : LUT3
    generic map(
      INIT => X"06"
    )
    port map (
      I0 => min_bajo(0),
      I1 => Q_n0359_inv,
      I2 => Mcount_min_bajo_val,
      O => min_bajo_0_rstpot_360
    );
  contador_diez_unidades_1_rstpot : LUT4
    generic map(
      INIT => X"006A"
    )
    port map (
      I0 => contador_diez_unidades(1),
      I1 => contador_diez_unidades(0),
      I2 => contador_diez_segundos_3_PWR_4_o_equal_76_o_inv_inv,
      I3 => Mcount_contador_diez_unidades_val,
      O => contador_diez_unidades_1_rstpot_344
    );
  hora_alto_0_rstpot : LUT6
    generic map(
      INIT => X"00000000AAAAA6AA"
    )
    port map (
      I0 => hora_alto(0),
      I1 => hora_bajo(3),
      I2 => hora_bajo(2),
      I3 => hora_bajo(1),
      I4 => hora_bajo(0),
      I5 => Mcount_hora_alto_val_108,
      O => hora_alto_0_rstpot_345
    );
  contador_diez_unidades_2_rstpot : LUT5
    generic map(
      INIT => X"00006AAA"
    )
    port map (
      I0 => contador_diez_unidades(2),
      I1 => contador_diez_unidades(1),
      I2 => contador_diez_unidades(0),
      I3 => contador_diez_segundos_3_PWR_4_o_equal_76_o_inv_inv,
      I4 => Mcount_contador_diez_unidades_val,
      O => contador_diez_unidades_2_rstpot_350
    );
  min_alto_1_rstpot : LUT4
    generic map(
      INIT => X"006A"
    )
    port map (
      I0 => min_alto(1),
      I1 => min_alto(0),
      I2 => min_bajo_3_PWR_4_o_equal_86_o_inv_inv,
      I3 => Mcount_min_alto_val,
      O => min_alto_1_rstpot_352
    );
  min_alto_2_rstpot : LUT5
    generic map(
      INIT => X"00006AAA"
    )
    port map (
      I0 => min_alto(2),
      I1 => min_alto(1),
      I2 => min_alto(0),
      I3 => min_bajo_3_PWR_4_o_equal_86_o_inv_inv,
      I4 => Mcount_min_alto_val,
      O => min_alto_2_rstpot_353
    );
  segundo_tick_0_rstpot : LUT4
    generic map(
      INIT => X"00D8"
    )
    port map (
      I0 => stop_IBUF_1,
      I1 => segundo_tick(0),
      I2 => Result_0_1,
      I3 => Reset_OR_DriverANDClockEnable1_185,
      O => segundo_tick_0_rstpot_347
    );
  segundo_tick_1_rstpot : LUT4
    generic map(
      INIT => X"00D8"
    )
    port map (
      I0 => stop_IBUF_1,
      I1 => segundo_tick(1),
      I2 => Result_1_1,
      I3 => Reset_OR_DriverANDClockEnable1_185,
      O => segundo_tick_1_rstpot_348
    );
  segundo_tick_2_rstpot : LUT4
    generic map(
      INIT => X"00D8"
    )
    port map (
      I0 => stop_IBUF_1,
      I1 => segundo_tick(2),
      I2 => Result_2_1,
      I3 => Reset_OR_DriverANDClockEnable1_185,
      O => segundo_tick_2_rstpot_349
    );
  segundo_tick_3_rstpot : LUT4
    generic map(
      INIT => X"00D8"
    )
    port map (
      I0 => stop_IBUF_1,
      I1 => segundo_tick(3),
      I2 => Result_3_1,
      I3 => Reset_OR_DriverANDClockEnable1_185,
      O => segundo_tick_3_rstpot_361
    );
  segundo_tick_4_rstpot : LUT4
    generic map(
      INIT => X"00D8"
    )
    port map (
      I0 => stop_IBUF_1,
      I1 => segundo_tick(4),
      I2 => Result_4_1,
      I3 => Reset_OR_DriverANDClockEnable1_185,
      O => segundo_tick_4_rstpot_362
    );
  segundo_tick_5_rstpot : LUT4
    generic map(
      INIT => X"00D8"
    )
    port map (
      I0 => stop_IBUF_1,
      I1 => segundo_tick(5),
      I2 => Result_5_1,
      I3 => Reset_OR_DriverANDClockEnable1_185,
      O => segundo_tick_5_rstpot_363
    );
  segundo_tick_6_rstpot : LUT4
    generic map(
      INIT => X"00D8"
    )
    port map (
      I0 => stop_IBUF_1,
      I1 => segundo_tick(6),
      I2 => Result_6_1,
      I3 => Reset_OR_DriverANDClockEnable1_185,
      O => segundo_tick_6_rstpot_364
    );
  segundo_tick_8_rstpot : LUT4
    generic map(
      INIT => X"00D8"
    )
    port map (
      I0 => stop_IBUF_1,
      I1 => segundo_tick(8),
      I2 => Result_8_1,
      I3 => Reset_OR_DriverANDClockEnable1_185,
      O => segundo_tick_8_rstpot_365
    );
  segundo_tick_9_rstpot : LUT4
    generic map(
      INIT => X"00D8"
    )
    port map (
      I0 => stop_IBUF_1,
      I1 => segundo_tick(9),
      I2 => Result_9_1,
      I3 => Reset_OR_DriverANDClockEnable1_185,
      O => segundo_tick_9_rstpot_366
    );
  segundo_tick_10_rstpot : LUT4
    generic map(
      INIT => X"00D8"
    )
    port map (
      I0 => stop_IBUF_1,
      I1 => segundo_tick(10),
      I2 => Result_10_1,
      I3 => Reset_OR_DriverANDClockEnable1_185,
      O => segundo_tick_10_rstpot_367
    );
  segundo_tick_11_rstpot : LUT4
    generic map(
      INIT => X"00D8"
    )
    port map (
      I0 => stop_IBUF_1,
      I1 => segundo_tick(11),
      I2 => Result_11_1,
      I3 => Reset_OR_DriverANDClockEnable1_185,
      O => segundo_tick_11_rstpot_368
    );
  Q_n0359_inv1 : LUT6
    generic map(
      INIT => X"20FF202020202020"
    )
    port map (
      I0 => contador_diez_unidades(1),
      I1 => contador_diez_unidades(0),
      I2 => contador_diez_unidades(2),
      I3 => btnDer_registro(1),
      I4 => btnDer_registro(0),
      I5 => contador_20_GND_4_o_equal_28_o,
      O => Q_n0359_inv
    );
  contador_diez_unidades_0_rstpot : LUT6
    generic map(
      INIT => X"0055008A005500AA"
    )
    port map (
      I0 => contador_diez_unidades(0),
      I1 => btnRst_registro(1),
      I2 => btnRst_registro(0),
      I3 => contador_diez_unidades_2_PWR_4_o_equal_81_o,
      I4 => contador_diez_segundos_3_PWR_4_o_equal_76_o_inv_inv,
      I5 => contador_20_GND_4_o_equal_28_o,
      O => contador_diez_unidades_0_rstpot_343
    );
  contador_diez_segundos_1_rstpot : LUT5
    generic map(
      INIT => X"00009CCC"
    )
    port map (
      I0 => stop_IBUF_1,
      I1 => contador_diez_segundos(1),
      I2 => puntos_index(0),
      I3 => segundo_tick_25_GND_4_o_equal_13_o,
      I4 => Mcount_contador_diez_segundos_val,
      O => contador_diez_segundos_1_rstpot_354
    );
  contador_diez_segundos_2_rstpot : LUT6
    generic map(
      INIT => X"000000009CCCCCCC"
    )
    port map (
      I0 => stop_IBUF_1,
      I1 => contador_diez_segundos(2),
      I2 => contador_diez_segundos(1),
      I3 => puntos_index(0),
      I4 => segundo_tick_25_GND_4_o_equal_13_o,
      I5 => Mcount_contador_diez_segundos_val,
      O => contador_diez_segundos_2_rstpot_355
    );
  min_alto_0_rstpot : LUT6
    generic map(
      INIT => X"00000000FFDF0020"
    )
    port map (
      I0 => min_bajo(3),
      I1 => min_bajo(2),
      I2 => min_bajo(1),
      I3 => min_bajo(0),
      I4 => min_alto(0),
      I5 => Mcount_min_alto_val,
      O => min_alto_0_rstpot_351
    );
  Mmux_hora_bajo_3_hora_bajo_3_mux_92_OUT12 : LUT6
    generic map(
      INIT => X"4545454555454545"
    )
    port map (
      I0 => hora_bajo(0),
      I1 => btnRst_registro(1),
      I2 => btnRst_registro(0),
      I3 => min_alto(2),
      I4 => min_alto(1),
      I5 => min_alto(0),
      O => hora_bajo_3_hora_bajo_3_mux_92_OUT_0_Q
    );
  pendulo_0_rstpot : LUT3
    generic map(
      INIT => X"9A"
    )
    port map (
      I0 => pendulo(0),
      I1 => stop_IBUF_1,
      I2 => segundo_tick_25_GND_4_o_equal_13_o,
      O => pendulo_0_rstpot_339
    );
  segundo_tick_16_rstpot : LUT4
    generic map(
      INIT => X"00E4"
    )
    port map (
      I0 => stop_inv,
      I1 => segundo_tick(16),
      I2 => Result_16_1,
      I3 => Reset_OR_DriverANDClockEnable1_185,
      O => segundo_tick_16_rstpot_369
    );
  segundo_tick_16 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => segundo_tick_16_rstpot_369,
      Q => segundo_tick(16)
    );
  segundo_tick_18_rstpot : LUT4
    generic map(
      INIT => X"00E4"
    )
    port map (
      I0 => stop_inv,
      I1 => segundo_tick(18),
      I2 => Result_18_1,
      I3 => Reset_OR_DriverANDClockEnable1_185,
      O => segundo_tick_18_rstpot_370
    );
  segundo_tick_18 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => segundo_tick_18_rstpot_370,
      Q => segundo_tick(18)
    );
  segundo_tick_24_rstpot : LUT4
    generic map(
      INIT => X"00E4"
    )
    port map (
      I0 => stop_inv,
      I1 => segundo_tick(24),
      I2 => Result(24),
      I3 => Reset_OR_DriverANDClockEnable1_185,
      O => segundo_tick_24_rstpot_371
    );
  segundo_tick_24 : FD
    generic map(
      INIT => '0'
    )
    port map (
      C => clk_BUFGP_0,
      D => segundo_tick_24_rstpot_371,
      Q => segundo_tick(24)
    );
  contador_0 : FD
    port map (
      C => clk_BUFGP_0,
      D => contador_0_rstpot_372,
      Q => contador(0)
    );
  contador_1 : FD
    port map (
      C => clk_BUFGP_0,
      D => contador_1_rstpot_373,
      Q => contador(1)
    );
  contador_2 : FD
    port map (
      C => clk_BUFGP_0,
      D => contador_2_rstpot_374,
      Q => contador(2)
    );
  contador_3 : FD
    port map (
      C => clk_BUFGP_0,
      D => contador_3_rstpot_375,
      Q => contador(3)
    );
  contador_4 : FD
    port map (
      C => clk_BUFGP_0,
      D => contador_4_rstpot_376,
      Q => contador(4)
    );
  contador_5 : FD
    port map (
      C => clk_BUFGP_0,
      D => contador_5_rstpot_377,
      Q => contador(5)
    );
  contador_6 : FD
    port map (
      C => clk_BUFGP_0,
      D => contador_6_rstpot_378,
      Q => contador(6)
    );
  contador_7 : FD
    port map (
      C => clk_BUFGP_0,
      D => contador_7_rstpot_379,
      Q => contador(7)
    );
  contador_8 : FD
    port map (
      C => clk_BUFGP_0,
      D => contador_8_rstpot_380,
      Q => contador(8)
    );
  contador_9 : FD
    port map (
      C => clk_BUFGP_0,
      D => contador_9_rstpot_381,
      Q => contador(9)
    );
  contador_10 : FD
    port map (
      C => clk_BUFGP_0,
      D => contador_10_rstpot_382,
      Q => contador(10)
    );
  contador_11 : FD
    port map (
      C => clk_BUFGP_0,
      D => contador_11_rstpot_383,
      Q => contador(11)
    );
  contador_12 : FD
    port map (
      C => clk_BUFGP_0,
      D => contador_12_rstpot_384,
      Q => contador(12)
    );
  contador_13 : FD
    port map (
      C => clk_BUFGP_0,
      D => contador_13_rstpot_385,
      Q => contador(13)
    );
  contador_14 : FD
    port map (
      C => clk_BUFGP_0,
      D => contador_14_rstpot_386,
      Q => contador(14)
    );
  contador_15 : FD
    port map (
      C => clk_BUFGP_0,
      D => contador_15_rstpot_387,
      Q => contador(15)
    );
  contador_16 : FD
    port map (
      C => clk_BUFGP_0,
      D => contador_16_rstpot_388,
      Q => contador(16)
    );
  contador_17 : FD
    port map (
      C => clk_BUFGP_0,
      D => contador_17_rstpot_389,
      Q => contador(17)
    );
  contador_18 : FD
    port map (
      C => clk_BUFGP_0,
      D => contador_18_rstpot_390,
      Q => contador(18)
    );
  contador_19 : FD
    port map (
      C => clk_BUFGP_0,
      D => contador_19_rstpot_391,
      Q => contador(19)
    );
  contador_20 : FD
    port map (
      C => clk_BUFGP_0,
      D => contador_20_rstpot_392,
      Q => contador(20)
    );
  segundo_tick_7 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk_BUFGP_0,
      D => segundo_tick_7_rstpot_393,
      Q => segundo_tick(7)
    );
  segundo_tick_12 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk_BUFGP_0,
      D => segundo_tick_12_rstpot_394,
      Q => segundo_tick(12)
    );
  segundo_tick_13 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk_BUFGP_0,
      D => segundo_tick_13_rstpot_395,
      Q => segundo_tick(13)
    );
  segundo_tick_14 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk_BUFGP_0,
      D => segundo_tick_14_rstpot_396,
      Q => segundo_tick(14)
    );
  segundo_tick_15 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk_BUFGP_0,
      D => segundo_tick_15_rstpot_397,
      Q => segundo_tick(15)
    );
  segundo_tick_17 : FD
    generic map(
      INIT => '1'
    )
    port map (
      C => clk_BUFGP_0,
      D => segundo_tick_17_rstpot_398,
      Q => segundo_tick(17)
    );
  segundo_tick_7_rstpot : LUT5
    generic map(
      INIT => X"55514440"
    )
    port map (
      I0 => Q_n0298,
      I1 => stop_inv,
      I2 => Result_7_1,
      I3 => segundo_tick_25_GND_4_o_equal_13_o,
      I4 => segundo_tick(7),
      O => segundo_tick_7_rstpot_393
    );
  segundo_tick_12_rstpot : LUT5
    generic map(
      INIT => X"55514440"
    )
    port map (
      I0 => Q_n0298,
      I1 => stop_inv,
      I2 => Result_12_1,
      I3 => segundo_tick_25_GND_4_o_equal_13_o,
      I4 => segundo_tick(12),
      O => segundo_tick_12_rstpot_394
    );
  segundo_tick_13_rstpot : LUT5
    generic map(
      INIT => X"55514440"
    )
    port map (
      I0 => Q_n0298,
      I1 => stop_inv,
      I2 => Result_13_1,
      I3 => segundo_tick_25_GND_4_o_equal_13_o,
      I4 => segundo_tick(13),
      O => segundo_tick_13_rstpot_395
    );
  segundo_tick_14_rstpot : LUT5
    generic map(
      INIT => X"55514440"
    )
    port map (
      I0 => Q_n0298,
      I1 => stop_inv,
      I2 => Result_14_1,
      I3 => segundo_tick_25_GND_4_o_equal_13_o,
      I4 => segundo_tick(14),
      O => segundo_tick_14_rstpot_396
    );
  segundo_tick_15_rstpot : LUT5
    generic map(
      INIT => X"55514440"
    )
    port map (
      I0 => Q_n0298,
      I1 => stop_inv,
      I2 => Result_15_1,
      I3 => segundo_tick_25_GND_4_o_equal_13_o,
      I4 => segundo_tick(15),
      O => segundo_tick_15_rstpot_397
    );
  segundo_tick_17_rstpot : LUT5
    generic map(
      INIT => X"55514440"
    )
    port map (
      I0 => Q_n0298,
      I1 => stop_inv,
      I2 => Result_17_1,
      I3 => segundo_tick_25_GND_4_o_equal_13_o,
      I4 => segundo_tick(17),
      O => segundo_tick_17_rstpot_398
    );
  contador_0_rstpot : LUT4
    generic map(
      INIT => X"8AAA"
    )
    port map (
      I0 => Result(0),
      I1 => btnRst_registro(1),
      I2 => contador_20_GND_4_o_equal_28_o,
      I3 => btnRst_registro(0),
      O => contador_0_rstpot_372
    );
  contador_1_rstpot : LUT4
    generic map(
      INIT => X"8AAA"
    )
    port map (
      I0 => Result(1),
      I1 => btnRst_registro(1),
      I2 => contador_20_GND_4_o_equal_28_o,
      I3 => btnRst_registro(0),
      O => contador_1_rstpot_373
    );
  contador_2_rstpot : LUT4
    generic map(
      INIT => X"8AAA"
    )
    port map (
      I0 => Result(2),
      I1 => btnRst_registro(1),
      I2 => contador_20_GND_4_o_equal_28_o,
      I3 => btnRst_registro(0),
      O => contador_2_rstpot_374
    );
  contador_3_rstpot : LUT4
    generic map(
      INIT => X"8AAA"
    )
    port map (
      I0 => Result(3),
      I1 => btnRst_registro(1),
      I2 => contador_20_GND_4_o_equal_28_o,
      I3 => btnRst_registro(0),
      O => contador_3_rstpot_375
    );
  contador_4_rstpot : LUT4
    generic map(
      INIT => X"8AAA"
    )
    port map (
      I0 => Result(4),
      I1 => btnRst_registro(1),
      I2 => contador_20_GND_4_o_equal_28_o,
      I3 => btnRst_registro(0),
      O => contador_4_rstpot_376
    );
  contador_5_rstpot : LUT4
    generic map(
      INIT => X"8AAA"
    )
    port map (
      I0 => Result(5),
      I1 => btnRst_registro(1),
      I2 => contador_20_GND_4_o_equal_28_o,
      I3 => btnRst_registro(0),
      O => contador_5_rstpot_377
    );
  contador_6_rstpot : LUT4
    generic map(
      INIT => X"8AAA"
    )
    port map (
      I0 => Result(6),
      I1 => btnRst_registro(1),
      I2 => contador_20_GND_4_o_equal_28_o,
      I3 => btnRst_registro(0),
      O => contador_6_rstpot_378
    );
  contador_7_rstpot : LUT4
    generic map(
      INIT => X"8AAA"
    )
    port map (
      I0 => Result(7),
      I1 => btnRst_registro(1),
      I2 => contador_20_GND_4_o_equal_28_o,
      I3 => btnRst_registro(0),
      O => contador_7_rstpot_379
    );
  contador_8_rstpot : LUT4
    generic map(
      INIT => X"8AAA"
    )
    port map (
      I0 => Result(8),
      I1 => btnRst_registro(1),
      I2 => contador_20_GND_4_o_equal_28_o,
      I3 => btnRst_registro(0),
      O => contador_8_rstpot_380
    );
  contador_9_rstpot : LUT4
    generic map(
      INIT => X"8AAA"
    )
    port map (
      I0 => Result(9),
      I1 => btnRst_registro(1),
      I2 => contador_20_GND_4_o_equal_28_o,
      I3 => btnRst_registro(0),
      O => contador_9_rstpot_381
    );
  contador_10_rstpot : LUT4
    generic map(
      INIT => X"8AAA"
    )
    port map (
      I0 => Result(10),
      I1 => btnRst_registro(1),
      I2 => contador_20_GND_4_o_equal_28_o,
      I3 => btnRst_registro(0),
      O => contador_10_rstpot_382
    );
  contador_11_rstpot : LUT4
    generic map(
      INIT => X"8AAA"
    )
    port map (
      I0 => Result(11),
      I1 => btnRst_registro(1),
      I2 => contador_20_GND_4_o_equal_28_o,
      I3 => btnRst_registro(0),
      O => contador_11_rstpot_383
    );
  contador_12_rstpot : LUT4
    generic map(
      INIT => X"8AAA"
    )
    port map (
      I0 => Result(12),
      I1 => btnRst_registro(1),
      I2 => contador_20_GND_4_o_equal_28_o,
      I3 => btnRst_registro(0),
      O => contador_12_rstpot_384
    );
  contador_13_rstpot : LUT4
    generic map(
      INIT => X"8AAA"
    )
    port map (
      I0 => Result(13),
      I1 => btnRst_registro(1),
      I2 => contador_20_GND_4_o_equal_28_o,
      I3 => btnRst_registro(0),
      O => contador_13_rstpot_385
    );
  contador_14_rstpot : LUT4
    generic map(
      INIT => X"8AAA"
    )
    port map (
      I0 => Result(14),
      I1 => btnRst_registro(1),
      I2 => contador_20_GND_4_o_equal_28_o,
      I3 => btnRst_registro(0),
      O => contador_14_rstpot_386
    );
  contador_15_rstpot : LUT4
    generic map(
      INIT => X"8AAA"
    )
    port map (
      I0 => Result(15),
      I1 => btnRst_registro(1),
      I2 => contador_20_GND_4_o_equal_28_o,
      I3 => btnRst_registro(0),
      O => contador_15_rstpot_387
    );
  contador_16_rstpot : LUT4
    generic map(
      INIT => X"8AAA"
    )
    port map (
      I0 => Result(16),
      I1 => btnRst_registro(1),
      I2 => contador_20_GND_4_o_equal_28_o,
      I3 => btnRst_registro(0),
      O => contador_16_rstpot_388
    );
  contador_17_rstpot : LUT4
    generic map(
      INIT => X"8AAA"
    )
    port map (
      I0 => Result(17),
      I1 => btnRst_registro(1),
      I2 => contador_20_GND_4_o_equal_28_o,
      I3 => btnRst_registro(0),
      O => contador_17_rstpot_389
    );
  contador_18_rstpot : LUT4
    generic map(
      INIT => X"8AAA"
    )
    port map (
      I0 => Result(18),
      I1 => btnRst_registro(1),
      I2 => contador_20_GND_4_o_equal_28_o,
      I3 => btnRst_registro(0),
      O => contador_18_rstpot_390
    );
  contador_19_rstpot : LUT4
    generic map(
      INIT => X"8AAA"
    )
    port map (
      I0 => Result(19),
      I1 => btnRst_registro(1),
      I2 => contador_20_GND_4_o_equal_28_o,
      I3 => btnRst_registro(0),
      O => contador_19_rstpot_391
    );
  contador_20_rstpot : LUT4
    generic map(
      INIT => X"8AAA"
    )
    port map (
      I0 => Result(20),
      I1 => btnRst_registro(1),
      I2 => contador_20_GND_4_o_equal_28_o,
      I3 => btnRst_registro(0),
      O => contador_20_rstpot_392
    );
  clk_BUFGP : BUFGP
    port map (
      I => clk,
      O => clk_BUFGP_0
    );
  Mcount_contador_lut_0_INV_0 : INV
    port map (
      I => contador(0),
      O => Mcount_contador_lut(0)
    );
  Mcount_segundo_tick_lut_1_INV_0 : INV
    port map (
      I => segundo_tick(1),
      O => Mcount_segundo_tick_lut(1)
    );
  Mcount_segundo_tick_lut_2_INV_0 : INV
    port map (
      I => segundo_tick(2),
      O => Mcount_segundo_tick_lut(2)
    );
  Mcount_segundo_tick_lut_3_INV_0 : INV
    port map (
      I => segundo_tick(3),
      O => Mcount_segundo_tick_lut(3)
    );
  Mcount_segundo_tick_lut_4_INV_0 : INV
    port map (
      I => segundo_tick(4),
      O => Mcount_segundo_tick_lut(4)
    );
  Mcount_segundo_tick_lut_5_INV_0 : INV
    port map (
      I => segundo_tick(5),
      O => Mcount_segundo_tick_lut(5)
    );
  Mcount_segundo_tick_lut_6_INV_0 : INV
    port map (
      I => segundo_tick(6),
      O => Mcount_segundo_tick_lut(6)
    );
  Mcount_segundo_tick_lut_7_INV_0 : INV
    port map (
      I => segundo_tick(7),
      O => Mcount_segundo_tick_lut(7)
    );
  Mcount_segundo_tick_lut_8_INV_0 : INV
    port map (
      I => segundo_tick(8),
      O => Mcount_segundo_tick_lut(8)
    );
  Mcount_segundo_tick_lut_9_INV_0 : INV
    port map (
      I => segundo_tick(9),
      O => Mcount_segundo_tick_lut(9)
    );
  Mcount_segundo_tick_lut_10_INV_0 : INV
    port map (
      I => segundo_tick(10),
      O => Mcount_segundo_tick_lut(10)
    );
  Mcount_segundo_tick_lut_11_INV_0 : INV
    port map (
      I => segundo_tick(11),
      O => Mcount_segundo_tick_lut(11)
    );
  Mcount_segundo_tick_lut_12_INV_0 : INV
    port map (
      I => segundo_tick(12),
      O => Mcount_segundo_tick_lut(12)
    );
  Mcount_segundo_tick_lut_13_INV_0 : INV
    port map (
      I => segundo_tick(13),
      O => Mcount_segundo_tick_lut(13)
    );
  Mcount_segundo_tick_lut_14_INV_0 : INV
    port map (
      I => segundo_tick(14),
      O => Mcount_segundo_tick_lut(14)
    );
  Mcount_segundo_tick_lut_15_INV_0 : INV
    port map (
      I => segundo_tick(15),
      O => Mcount_segundo_tick_lut(15)
    );
  Mcount_segundo_tick_lut_16_INV_0 : INV
    port map (
      I => segundo_tick(16),
      O => Mcount_segundo_tick_lut(16)
    );
  Mcount_segundo_tick_lut_17_INV_0 : INV
    port map (
      I => segundo_tick(17),
      O => Mcount_segundo_tick_lut(17)
    );
  Mcount_segundo_tick_lut_18_INV_0 : INV
    port map (
      I => segundo_tick(18),
      O => Mcount_segundo_tick_lut(18)
    );
  Mcount_segundo_tick_lut_19_INV_0 : INV
    port map (
      I => segundo_tick(19),
      O => Mcount_segundo_tick_lut(19)
    );
  Mcount_segundo_tick_lut_20_INV_0 : INV
    port map (
      I => segundo_tick(20),
      O => Mcount_segundo_tick_lut(20)
    );
  Mcount_segundo_tick_lut_21_INV_0 : INV
    port map (
      I => segundo_tick(21),
      O => Mcount_segundo_tick_lut(21)
    );
  Mcount_segundo_tick_lut_22_INV_0 : INV
    port map (
      I => segundo_tick(22),
      O => Mcount_segundo_tick_lut(22)
    );
  Mcount_segundo_tick_lut_23_INV_0 : INV
    port map (
      I => segundo_tick(23),
      O => Mcount_segundo_tick_lut(23)
    );
  Mcount_segundo_tick_lut_24_INV_0 : INV
    port map (
      I => segundo_tick(24),
      O => Mcount_segundo_tick_lut(24)
    );
  Mcount_segundo_tick_lut_25_INV_0 : INV
    port map (
      I => segundo_tick(25),
      O => Mcount_segundo_tick_lut(25)
    );
  pendulo_1_inv_14_OUT_0_1_INV_0 : INV
    port map (
      I => pendulo(0),
      O => led_0_inv
    );
  stop_inv1_INV_0 : INV
    port map (
      I => stop_IBUF_1,
      O => stop_inv
    );
  Mcount_puntos_index_xor_0_11_INV_0 : INV
    port map (
      I => puntos_index(0),
      O => Mcount_puntos_index
    );
  segmento_7_Q : MUXF7
    port map (
      I0 => N12,
      I1 => N13,
      S => puntos_index(3),
      O => segmento_7_OBUF_82
    );
  segmento_7_F : LUT6
    generic map(
      INIT => X"FAF57277AF5F5FAF"
    )
    port map (
      I0 => contador(17),
      I1 => puntos_index(2),
      I2 => puntos_index(0),
      I3 => puntos_index(1),
      I4 => puntos_index(4),
      I5 => contador(16),
      O => N12
    );
  segmento_7_G : LUT6
    generic map(
      INIT => X"FAAFF55F409D404A"
    )
    port map (
      I0 => contador(16),
      I1 => puntos_index(2),
      I2 => puntos_index(1),
      I3 => contador(17),
      I4 => puntos_index(0),
      I5 => puntos_index(4),
      O => N13
    );

end Structure;

