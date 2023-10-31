# Опис алгоритму генерації дороги

Програма починає своє виконування з запиту до користувача про кількість вершин-перехресть графу та кількість ребер для видалення. Граф завжди має вигляд сітки розміром n*n. Головна іде алгоритму полягає в тому, щоб видаляти ребра-дороги між вершинами-перехрестями. Спочатку, випадковим чинном обираємо яке ребро ми хочемо видалити. Після видалення, викликаємо функцію is_connected(), щоб перевірити, чи наш граф залишився зв'язний. У зворотному випадку ми повертаємо наше видалене ребро і переходимо до іншого ребра. Функція is_connected() собою являє методом обходу в глубину для перевірки зв'язності графа. В функції запускається цикл, який виконується, поки є вузли в __stack__. Якщо вузол ще не був відвіданий, він додається до множини visited, і всі його сусіди, які ще не були відвідані, додаються до stack. Функція повертає True або False, в залежності від рівності відвіданих вузлів з загальною кількістю вузлів у графі.