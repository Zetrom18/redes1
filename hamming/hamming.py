import sys

if len(sys.argv) < 2:
    print("Parametros insuficientes")
    exit(1)

parity_positions = [0, 1, 3, 7]
parity_indexes_list = [
    [2, 4, 6, 8, 10, 12, 14],
    [2, 5, 6, 9, 10, 13, 14],
    [4, 5, 6, 11, 12, 13, 14],
    [8, 9, 10, 11, 12, 13, 14]
]

def binary_to_int(binary, size=4):
    binary = binary[::-1]
    sum = 0
    for i in range(size):
        sum += int(binary[i])*(2**i)
    return sum

def text_from_bits(bits):
    text = ""

    while len(bits) > 7:
        text += chr(binary_to_int(bits[:8], 8))
        bits = bits[8:]
    return text

def change_char(s, p, r):
    return s[:p]+r+s[p+1:]

def compute_parity(parity_indexes, encoded_bits):
    bit_sum = 0
    for bit in parity_indexes:
        bit_sum += int(encoded_bits[bit])

    return str(bit_sum % 2)

def hamming_encode(bitset):
    encoded_bits = ''
    for i in range(15):
        if (i in parity_positions):
            encoded_bits += 'a'
            continue

        encoded_bits += str(bitset[0])
        bitset = bitset[1:]

    parity = ''
    for parity_indexes in parity_indexes_list:
        parity += compute_parity(parity_indexes, encoded_bits)

    for position in parity_positions:
        parity_bit = parity[0]
        parity = parity[1:]
        encoded_bits = change_char(encoded_bits, position, parity_bit)

    return encoded_bits


def encode():
    with open(sys.argv[2], "rb") as f:
        lista=list(f.read())
        bitstring = ""
        for byte in lista:
            bitstring += ("00000000"+"{0:b}".format(byte))[-8:]

    array = []
    while len(bitstring) > 0:
        array.append(bitstring[:11])
        bitstring = bitstring[11:]
    array[len(array)-1] = (array[len(array)-1]+"00000000000")[:11]

    encoded_message = ''
    for bitset in array:
        encoded_message += hamming_encode(bitset)

    with open("hamming_encoded.txt", "w") as f:
        while len(encoded_message) > 0:
            f.write(encoded_message[:15])
            encoded_message = encoded_message[15:]
            f.write(" ")
    print('Salvo como "hamming_encoded.txt"')

def hamming_decode(bitset):
    active_bits = []
    for index in range(len(bitset)):
        if bitset[index] == "0":
            continue
        active_bits.append(("0000"+"{0:b}".format(index+1))[-4:])
    parity_xor = ""

    for parity_index in range(4):
        sum = 0
        for index in active_bits:
            sum += int(index[parity_index])
        parity_xor += str(sum % 2)

    if parity_xor != "0000":
        error_index = binary_to_int(parity_xor) - 1
        if error_index in parity_positions:
            print("Erro incorrigivel!")
            exit(1)
        if bitset[error_index] == "1":
            bitset = change_char(bitset, error_index, "0")
        else:
            bitset = change_char(bitset, error_index, "1")

    return_string = ""
    for i in range(len(bitset)):
        if i in parity_positions:
            continue
        return_string += bitset[i]
    return return_string

def decode():
    with open(sys.argv[2], "r") as f:
        bitstring = f.read().replace(" ","").replace("\n","")
        array = []
        while len(bitstring) > 0:
            array.append(bitstring[:15])
            bitstring = bitstring[15:]
    decoded_message = ""
    for bitset in array:
        decoded_message += hamming_decode(bitset)

    with open("hamming_decoded.txt", "w") as f:
        f.write(text_from_bits(decoded_message))
    print('Salvo como "hamming_decoded.txt"')


if sys.argv[1] == "-e":
    encode()
elif sys.argv[1] == "-d":
    decode()
else:
    print("Parametros incorretos")
