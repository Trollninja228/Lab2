from itertools import permutations

# Данные
numbers = [2, 13, 7, 6, 6, 5, 7, 4, 3]
target_sum = 20
subset_size = 6

# Считаем количество подходящих перестановок
count = 0
valid_permutations = []

# Генерация всех подмножеств из 6 элементов (без повторного использования одного и того же числа)
for subset in permutations(numbers, subset_size):
    if sum(subset) <= target_sum:
        count += 1
        valid_permutations.append(subset)

# Результаты
print("Количество подходящих перестановок:", count)
print("Примеры подходящих перестановок (максимум 5):", valid_permutations[:5])
