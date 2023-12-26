def decimal_to_binary(n):
    binary = bin(n)[2:].zfill(32)
    return [int(bit) for bit in binary]

def find_most_significant_bit(binary):
    for i in range(31, -1, -1):
        if binary[i] == 1:
            return i
    return -1

def print_binary(binary):
    i = find_most_significant_bit(binary)
    if i == -1:
        print("0")
    else:
        print("".join(map(str, binary[i::-1])))

def bitwise_and(binary1, binary2):
    return [bit1 & bit2 for bit1, bit2 in zip(binary1, binary2)]

def bitwise_or(binary1, binary2):
    return [bit1 | bit2 for bit1, bit2 in zip(binary1, binary2)]

def bitwise_xor(binary1, binary2):
    return [bit1 ^ bit2 for bit1, bit2 in zip(binary1, binary2)]

def bitwise_xnor(binary1, binary2):
    return [not (bit1 ^ bit2) for bit1, bit2 in zip(binary1, binary2)]

def bitwise_complement(binary):
    return [not bit for bit in binary]

# Main program
num1 = int(input("Enter the first unsigned decimal number: "))
num2 = int(input("Enter the second unsigned decimal number: "))

binary1 = decimal_to_binary(num1)
binary2 = decimal_to_binary(num2)

print("Binary representation of", num1, ": ", end="")
print_binary(binary1)

print("Binary representation of", num2, ": ", end="")
print_binary(binary2)

print("\nBitwise AND: ", end="")
print_binary(bitwise_and(binary1, binary2))

print("Bitwise OR: ", end="")
print_binary(bitwise_or(binary1, binary2))

print("Bitwise XOR: ", end="")
print_binary(bitwise_xor(binary1, binary2))

print("Bitwise XNOR: ", end="")
print_binary(bitwise_xnor(binary1, binary2))

print("Bitwise Complement of", num1, ": ", end="")
print_binary(bitwise_complement(binary1))
