#include <iostream>
#include <bitset>

int replacement(int n, int first_byte_number, int second_byte_number){
    int mask(0x0000ff);

    if (second_byte_number < first_byte_number){
        int tmp = second_byte_number;
        second_byte_number = first_byte_number;
        first_byte_number = tmp;
    }

    int result = n;

    int first_byte = ((n >> ((first_byte_number - 1)) * 8)) & mask;
    int second_byte = ((n >> ((second_byte_number - 1)) * 8)) & mask;

    int first_byte_delete_mask = 0b11111111111111111111111111111111;
    first_byte_delete_mask = first_byte_delete_mask ^ (0x000000ff << ((first_byte_number - 1) * 8));
    int second_byte_delete_mask = 0b11111111111111111111111111111111;
    second_byte_delete_mask = second_byte_delete_mask ^ (0x000000ff << ((second_byte_number - 1) * 8));

    result &= first_byte_delete_mask;
    result &= second_byte_delete_mask;

    int first_byte_insert_mask = first_byte << (second_byte_number - 1) * 8;
    int second_byte_insert_mask = second_byte << (first_byte_number - 1) * 8;

    result |= first_byte_insert_mask;
    result |= second_byte_insert_mask;

    return result;

}

int main() {

    int n{1415124195};
    std::cout << std::bitset<32>(n) << std::endl;
    n = replacement(n, 1, 4);
    std::cout << std::bitset<32>(n) << std::endl;

}
