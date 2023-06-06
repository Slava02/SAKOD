import numpy as np
# lowest_cell:
#  Определяет самую маленьку ячейку в таблице
def lowest_cell(table):
    # Определяем бесконечность по умолчанию
    min_cell = float("inf")
    x, y = -1, -1

    # Проходимся по каждой ячейке в поиске минимальной
    for i in range(len(table)):
        for j in range(len(table[i])):
            if table[i][j] < min_cell:
                min_cell = table[i][j]
                x, y = i, j

    # Возвращает координаты ячейки
    return x, y


# join_labels:
#   Соеденяет 2 обозначения в одно
def join_labels(labels, a, b):
    # Меняем местами индексы, если они не упорядочены
    if b < a:
        a, b = b, a

    # Соеденяем обозначения в 1-ом индексе
    labels[a] = "(" + labels[a] + "," + labels[b] + ")"

    # Удаляем избыточное обозначение во 2-ом индексе.
    del labels[b]


# join_table:
#   Объединяет записи таблицы в ячейке (a, b) путем усреднения их записей данных
def join_table(table, a, b):
    # Меняем местами индексы, если они не упорядочены
    if b < a:
        a, b = b, a

    # Для меньшего из двух индексов: пересобираем весь ряд (A, i), где i < A
    row = []
    for i in range(0, a):
        row.append((table[a][i] + table[b][i])/2)
    table[a] = row
    
    # После этого, пересобираем всю колонну (i, A), где i > A
    for i in range(a+1, b):
        table[i][a] = (table[i][a]+table[b][i])/2
        
    #   Все оставшиеся значения получаем со строки i
    for i in range(b+1, len(table)):
        table[i][a] = (table[i][a]+table[i][b])/2
        # Удаляем лишнюю колонку
        del table[i][b]

    # Удаляем лишний индекс строки
    del table[b]


# UPGMA:
#   Запускает алгоритм на выбранной таблице
def UPGMA(table, labels):
    # Пока все названия не соеденены...
    while len(labels) > 1:
        # Определяем минимальную клетку
        x, y = lowest_cell(table)

        # Объеденяем таблицу в выбранной клетке
        join_table(table, x, y)

        # Обновляем обозначения
        join_labels(labels, x, y)

    return labels[0]


# alpha_labels:
#   Создает ряд из обозначений по алфавиту
def alpha_labels(start, end):
    labels = []
    for i in range(ord(start), ord(end)+1):
        labels.append(chr(i))
    return labels

# letter:
#   Генерирует букву алфавита, номер которой запрашивается
def letter(number):
  first_letter_code = ord('A')
  your_letter_code = first_letter_code + number 
  return chr(your_letter_code)

# input_custom_matrix:
#   позволяет пользователю ввести половину симметричной матрицы
def input_custom_matrix(n):
    matrix = []
    empty = []
    for i in range(n):
        row = []
        for j in range(i + 1):
            row.append(float(input(f"Введите элемент ({i + 1}, {j + 1}): ")))
        matrix.append(row)
    matrix.insert(0, empty)
    return matrix

n = int(input("Введите размер матрицы: "))
matrix = input_custom_matrix(n)

# Test table data and corresponding labels
M_labels = alpha_labels("A", letter(n))   
print(M_labels)

UPGMA(matrix, M_labels)

# ПРИМЕР ИСПОЛЬЗВАНИЯ: 
# Введите размер матрицы: 6
# Введите элемент (1, 1): 19
# Введите элемент (2, 1): 27
# Введите элемент (2, 2): 31
# Введите элемент (3, 1): 8
# Введите элемент (3, 2): 18
# Введите элемент (3, 3): 26
# Введите элемент (4, 1): 33
# Введите элемент (4, 2): 36
# Введите элемент (4, 3): 41
# Введите элемент (4, 4): 31
# Введите элемент (5, 1): 18
# Введите элемент (5, 2): 1
# Введите элемент (5, 3): 32
# Введите элемент (5, 4): 17
# Введите элемент (5, 5): 35
# Введите элемент (6, 1): 13
# Введите элемент (6, 2): 13
# Введите элемент (6, 3): 29
# Введите элемент (6, 4): 14
# Введите элемент (6, 5): 28
# Введите элемент (6, 6): 12
# ['A', 'B', 'C', 'D', 'E', 'F', 'G']
# ((((A,D),((B,F),G)),C),E)
