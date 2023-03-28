import random
import math

# Función para calcular el valor de la función objetivo
def objective_function(x):
    fitness = x + abs(math.sin(32 * x))
    #si fitness es mayor de 100 lo ponemos a 0 para no contar el resultado
    if fitness > 100:
        fitness = 0
    return fitness


# Función para convertir un número en su representación binaria con un número fijo de bits
def to_binary(num, num_bits):
    binary = bin(num)[2:]
    padding = '0' * (num_bits - len(binary))
    return padding + binary

# Función para convertir un número binario en su equivalente decimal
def to_decimal(binary):
    return int(binary, 2)

# Función para aplicar la mutación a un individuo
def mutate(individual, mutation_prob):
    mutated = ''
    for bit in individual:
        if random.random() < mutation_prob:
            mutated += '1' if bit == '0' else '0'
        else:
            mutated += str(bit)
    return mutated


# Población inicial
population = []
for _ in range(10):
    x = random.uniform(0, 99)
    fitness = objective_function(x)
    num_bits = len('{0:.10f}'.format(fitness).replace('.', ''))
    binary = to_binary(int(fitness * 10**10), num_bits)
    population.append((x, fitness, binary))

# Número de bits de los valores de aptitud
num_bits = len(population[0][2])

# Ciclo de evolución
for generation in range(2):
    #print("Población inicial")
    for i in range(0,10):
        print(f"  x = {population[i][1]}")
    # Selección de parejas para reproducción
    parents = random.sample(population, len(population))

    # Creación de nuevos individuos mediante reproducción
    offspring = []
    for i in range(0, len(population), 2):
        parent1 = parents[i]
        parent2 = parents[i+1]
        crossover_point = random.randint(1, num_bits-1)
        child1 = parent1[0:2] + parent1[2:5] + parent2[5:7] + parent1[7:9] + parent1[9:12] + parent2[12:]
        child2 = parent1[0:2] + parent2[2:5] + parent1[5:7] + parent1[7:9] + parent2[9:12] + parent1[12:]
        child3 = parent2[0:2] + parent1[2:5] + parent2[5:7] + parent1[7:9] + parent1[9:12] + parent2[12:]
        child4 = parent2[0:2] + parent2[2:5] + parent1[5:7] + parent1[7:9] + parent2[9:12] + parent1[12:]
        offspring.append((child1,))
        offspring.append((child2,))
        offspring.append((child3,))
        offspring.append((child4,))


    # Mutación de los nuevos individuos
    mutation_prob = 1 / num_bits
    mutated_offspring = []
    for individual in offspring:
        mutated = mutate(individual[0], mutation_prob)
        mutated_offspring.append((mutated,))

    # Evaluación de los nuevos individuos
    new_population = []
    #print("hijos")
    for individual in mutated_offspring:
        fitness = to_decimal(individual[0]) / 10**10
        # verificamos que el redutado no pase de 100
        if(fitness > 100):
            fitness = 0
        #print("  hijo = " + str(fitness))
        x = fitness - abs(math.sin(32 * fitness))
        new_population.append((x, fitness, individual[0]))

    # Combinación de la población anterior y la nueva
    combined_population = population + new_population

    # Selección de los 10 mejores individuos para la siguiente generación
    sorted_population = sorted(combined_population, key=lambda x: x[1], reverse=True)
    population = sorted_population[:10]

print("Población Final")
for i in range(0,10):
    print(f"  x = {population[i][1]}")
# Resultado final
print("Mejor solución encontrada:")
best_solution = max(population, key=lambda x: x[1])
print(f"  x = {best_solution[0]}")
print(f"  f(x) = {best_solution[1]}")
