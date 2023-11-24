/* #include <stdio.h>
#include <stdint.h>
#include <string.h>

// Function prototypes
void sha256(const char *message, uint32_t hash[8]);
void sha256_transform(uint32_t state[8], const uint8_t data[64]);

int main() {
    const char *message = "Hello, SHA-256!";
    uint32_t hash[8];
    int i,j;
    sha256(message, hash);

    printf("SHA-256 Hash: ");
    for (i = 0; i < 8; ++i) {
        printf("%08x", hash[i]);
    }
    printf("\n");

    return 0;
}

void sha256(const char *message, uint32_t hash[8]) {
    // Initialize hash values
    uint32_t state[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    // Process the input message
    int i;
    size_t len = strlen(message);
    uint8_t data[64];
    size_t index = 0,l;
    uint64_t bitlen = len * 8;

    // Process each 512-bit block
    for(l = 0; l < len; ++l) {
        data[index++] = message[l];
        if (index == 64) {
            sha256_transform(state, data);
            index = 0;
        }
    }

    // Append '1' bit
    data[index++] = 0x80;

    // Append remaining bits (message length)
    while (index != 56) {
        if (index == 64) {
            sha256_transform(state, data);
            index = 0;
        }
        data[index++] = 0;
    }

    // Append the message length as a 64-bit integer
    for (i = 7; i >= 0; --i) {
        data[index++] = (bitlen >> (i * 8)) & 0xFF;
    }

    sha256_transform(state, data);

    // Copy the final hash to the result
    for (i = 0; i < 8; ++i) {
        hash[i] = state[i];
    }
}

// SHA-256 transformation
void sha256_transform(uint32_t state[8], const uint8_t data[64]) {
    // TODO: Implement the SHA-256 transformation
    // This is a placeholder and needs to be completed for a fully functional SHA-256 implementation
    // It involves bitwise operations, logical functions, and several rounds of processing
    // A complete implementation is beyond the scope of a simple example
}
*/









#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Function prototypes
void sha256(const char *message, uint32_t hash[8]);
void sha256_transform(uint32_t state[8], const uint8_t data[64]);

int main() {
    char message[100]; // Assuming a maximum message length of 100 characters
    uint32_t hash[8];
    int i;
    // Get user input for the message
    printf("Enter plain text: ");
    fgets(message, sizeof(message), stdin);

    // Remove newline character from the input
    size_t len = strlen(message);
    if (len > 0 && message[len - 1] == '\n') {
        message[len - 1] = '\0';
    }

    // Calculate SHA-256 hash
    sha256(message, hash);

    // Display the hash
    printf("SHA-256 Hash value: ");
    for (i = 0; i < 8; ++i) {
        printf("%08x", hash[i]);
    }
    printf("\n");

    return 0;
}

void sha256(const char *message, uint32_t hash[8]) {
    // Initialize hash values
    uint32_t state[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    // Process the input message
    size_t len = strlen(message);
    uint8_t data[64];
    int i;
    size_t index = 0,l;
    uint64_t bitlen = len * 8;

    // Process each 512-bit block
    for (l = 0; l < len; ++l) {
        data[index++] = message[l];
        if (index == 64) {
            sha256_transform(state, data);
            index = 0;
        }
    }

    // Append '1' bit
    data[index++] = 0x80;

    // Append remaining bits (message length)
    while (index != 56) {
        if (index == 64) {
            sha256_transform(state, data);
            index = 0;
        }
        data[index++] = 0;
    }

    // Append the message length as a 64-bit integer
    for (i = 7; i >= 0; --i) {
        data[index++] = (bitlen >> (i * 8)) & 0xFF;
    }

    sha256_transform(state, data);

    // Copy the final hash to the result
    for (i = 0; i < 8; ++i) {
        hash[i] = state[i];
    }
}

// SHA-256 transformation
void sha256_transform(uint32_t state[8], const uint8_t data[64]) {
    // TODO: Implement the SHA-256 transformation
    // This is a placeholder and needs to be completed for a fully functional SHA-256 implementation
    // It involves bitwise operations, logical functions, and several rounds of processing
    // A complete implementation is beyond the scope of a simple example
}



