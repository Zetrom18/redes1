import sys

if len(sys.argv) < 2:
    print("Parametros insuficientes")
    exit(1)


def change_char(s, p, r):
    return s[:p]+r+s[p+1:]

def compute_hemming(parity_indexes, encoded_bits):
    bit_sum = 0
    for bit in parity_indexes:
        bit_sum += encoded_bits[bit]

    return str(bit_sum % 2)

def hamming_encode(bitset):
    encoded_bits = ''
    ignored_positions = [0, 1, 3, 7]
    for i in range(14):
        if (i in ignored_positions):
            encoded_bits += 'a'
            continue

        encoded_bits += str(bitset[0])
        bitset = bitset[1:]

    parity = ''

    parity_indexes = [
        [2, 4, 6, 8, 10, 12, 14],
        [2, 5, 6, 9, 10, 13, 14],
        [4, 5, 6, 11, 12, 13, 14],
        [8, 9, 10, 11, 12, 13, 14]
    ]

    parity += compute_hemming(parity_indexes, encoded_bits)

    for position in ignored_positions:
        parity_bit = parity[0]
        parity = parity[1:]
        encoded_bits = change_char(encoded_bits, position, parity_bit)

    return encoded_bits


def encode(bitstring):
    array = []
    while len(bitstring) > 0:
        array.append(bitstring[:11])
        bitstring = bitstring[11:]

    # print(array)
    encoded_message = ''
    for bitset in array:
        encoded_message += hamming_encode(bitset)

    print(encoded_message)
        

with open(sys.argv[1], "rb") as f:
    lista=list(f.read())
    bitstring = ""
    for byte in lista:
        bitstring += "{0:b}".format(byte)
    encode(bitstring)
