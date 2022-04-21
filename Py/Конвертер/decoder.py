f = open('123.txt', encoding='UTF-8')

str = f.read()
#str = 'èçìåðåíèå ÷àñòîòû êîëåáàíèé è äëèíû âîëíû ïðè ðåçîíàíñå çâóêîâûõ'

str = str.encode("ISO-8859-1", errors='strict')
str = str.decode('cp1251', errors='strict')

f.close()

print(str)