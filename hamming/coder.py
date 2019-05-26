import sys

if len(sys.argv) < 2:
    print("Parametros insuficientes")
    exit(1)

def encode(bitstring):
    array = []
    while len(bitstring) > 0:
        array.append(bitstring[:11])
        bitstring = bitstring[11:]
    print(array)
    for bitset in array:
        

with open(sys.argv[1], "rb") as f:
    lista=list(f.read())
    bitstring = ""
    for byte in lista:
        bitstring += "{0:b}".format(byte)
    encode(bitstring)
