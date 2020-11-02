numbers = [3, 30, 34, 5, 9]
a = []
numbers = list(map(str, numbers))
numbers.sort(key = lambda x: x*3, reverse=True)
a = str(int(''.join(numbers)))
print(a)