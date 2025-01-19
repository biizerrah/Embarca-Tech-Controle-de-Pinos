#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pico/stdlib.h"

// Definições dos pinos
#define LED_RED 13

// Função para desligar LEDs
void turn_off_leds() {
    gpio_put(LED_RED, 0);

}

// Função para configurar os GPIOs
void setup_gpio() {
    // Configurar LEDs como saída
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);

    // Inicializar todos os LEDs desligados
    turn_off_leds();
}

void process_command(char command_){
    // Comparando o valor ASCII do caractere
    if (command_ == '1') {           // ASCII do caractere '1'
        gpio_put(LED_RED, 1);
        printf("LED vermelho ligado.\n");
        
    } else if (command_ == '0') {  // ASCII do caractere '0'
        printf("LEDS APAGADOS.\n");

        turn_off_leds();
    } else {
        printf("Comando desconhecido: %c\n", command_);
    }
}

int main() {
    // Inicializar a comunicação serial e configurar GPIOs
    stdio_init_all();  // Inicializa a comunicação serial com baud rate 115200
    setup_gpio();

    char command;

    while (1) {
        if (stdio_usb_connected()) {
            command = getchar(); // Ler caractere

            printf("Comando recebido: %c\n", command);

            process_command(command);//Função que processa comando
        }
    }

    return 0;
}
