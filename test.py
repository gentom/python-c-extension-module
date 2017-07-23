from gcallib import *

print('Addition')
s = sum(int(input('(int)first argument: ')),
        int(input('(int)second argument: ')))
print('sum: {}'.format(s))
print('------------------------')

print('Subtraction')
d = difference(int(input('(int)first argument: ')),
               int(input('(int)second argument: ')))
print('difference: {}'.format(d))
print('------------------------')

print('Multiplier')
p = product(int(input('(int)first argument: ')),
            int(input('(int)second argument: ')))
print('product: {}'.format(p))
print('------------------------')
