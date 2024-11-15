#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MIN_KEY -256
#define MAX_KEY 256

// Function to encrypt a single character with Caesar cipher
char encrypt_char(char c, int key) {
    // Normalize to lowercase
    c = tolower(c);
    // Calculate encrypted character, wrapping around 'a' to 'z'
    return ((c - 'a' + key) % 26 + 26) % 26 + 'a';
}

int main() {
    int num_chars;
    int key;
    char c;

    //random number generator
    srand(time(NULL));

    printf("Enter the number of characters to encrypt: ");
    if (scanf("%d", &num_chars) != 1 || num_chars <= 0) {
        printf("Invalid input: must be a positive integer.\n");
        return 1;
    }

    //Generate a random encryption key in range [-256, 256]
    key = (rand() % (MAX_KEY - MIN_KEY + 1)) + MIN_KEY;
    printf("Generated encryption key: %d\n", key);

    //Accept characters, encrypt if valid
    for (int i = 1; i <= num_chars; i++) {
        printf("Enter character %d: ", i);
        scanf(" %c", &c); //Read one character

        //Check if the character is alphabetic
        if (!isalpha(c)) {
            printf("Invalid input: must be a valid alphabetic character\n");
            i--; //repeat this character input
            continue;
        }

        //Encrypt and display the result
        char encrypted_char = encrypt_char(c, key);
        printf("Encrypted character: %c\n", encrypted_char);
    }

    return 0;
}
