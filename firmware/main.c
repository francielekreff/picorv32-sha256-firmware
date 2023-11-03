#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "uart.h"
#include "sha256.h"

#define reg_leds (*(volatile uint32_t*)0x03000000)

void main()
{	
	char data[] = "Hello, World!";
    char digest_string[DIGEST_STRING_SIZE];   

	reg_uart_clkdiv = 104;
	print("Booting PicoSoc...\n");

	while (getchar_prompt("Press ENTER to continue...\n") != '\r') { /* wait */ }

	print("\n");
	print("  ____  _          ____         ____\n");
	print(" |  _ \\(_) ___ ___/ ___|  ___  / ___|\n");
	print(" | |_) | |/ __/ _ \\___ \\ / _ \\| |\n");
	print(" |  __/| | (_| (_) |__) | (_) | |___\n");
	print(" |_|   |_|\\___\\___/____/ \\___/ \\____|\n");
	print("\n");

	print("Starting SHA-256...\n");

	sha256(data, 13, digest_string);

	print("SHA-256 Done!\n");
	
	print("\n");
	print("Data: ");
	print(data);
	print("\n");

	print("\n");
	print("Digest: ");
	print(digest_string);
	print("\n");
}