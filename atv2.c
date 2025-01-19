#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"

// Definições dos pinos
#define LED_RED 13
#define LED_BLUE 12
#define LED_GREEN 11
#define BUZZER 21

// Função para desligar LEDs e buzzer
void turn_off_all() {
    gpio_put(LED_RED, 0);
    gpio_put(LED_BLUE, 0);
    gpio_put(LED_GREEN, 0);
    gpio_put(BUZZER, 0);
}

// Função para ligar todos os LEDs ao mesmo tempo
void turn_on_all_leds() {
    gpio_put(LED_RED, 1);
    gpio_put(LED_BLUE, 1);
    gpio_put(LED_GREEN, 1);
    printf("Todos os LEDs ligados.\n");
}

// Função para configurar os GPIOs
void setup_gpio() {
    // Configurar LEDs como saída
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    
    // Configurar Buzzer como saída
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);

    // Inicializar todos os LEDs e buzzer desligados
    turn_off_all();
}

// Função para gerar um som no buzzer por uma determinada frequência
void play_tone(int frequency, int duration_ms) {
    int period = 1000000 / frequency; // período em microssegundos
    int half_period = period / 2;

    int cycles = duration_ms * 1000 / period;  // número de ciclos para o tempo solicitado
    for (int i = 0; i < cycles; i++) {
        gpio_put(BUZZER, 1);  // Liga o buzzer
        sleep_us(half_period); // Espera metade do período
        gpio_put(BUZZER, 0);  // Desliga o buzzer
        sleep_us(half_period); // Espera a outra metade do período
    }
}

// Função para processar comandos
void process_command(char command_) {
    // Comando para o LED vermelho
    if (command_ == '1') {           
        turn_off_all();  // Desliga todos os outros
        gpio_put(LED_RED, 1);
        printf("LED vermelho ligado.\n");

    // Comando para o LED azul
    } else if (command_ == '2') {    
        turn_off_all();
        gpio_put(LED_BLUE, 1);
        printf("LED azul ligado.\n");

    // Comando para o LED verde
    } else if (command_ == '3') {    
        turn_off_all();
        gpio_put(LED_GREEN, 1);
        printf("LED verde ligado.\n");

    // Comando para o Buzzer (som com melodia por 2 segundos)
    } else if (command_ == '4') {    
        turn_off_all();
        printf("Buzzer ativado com melodia.\n");

        // Tocar uma sequência de notas (frequências) no buzzer por 2 segundos
        play_tone(523, 200);  // C (Dó)
        play_tone(587, 200);  // D (Ré)
        play_tone(659, 200);  // E (Mi)
        play_tone(698, 200);  // F (Fá)
        play_tone(784, 200);  // G (Sol)
        play_tone(880, 200);  // A (Lá)
        play_tone(987, 200);  // B (Si)
        play_tone(1046, 200); // C (Dó) novamente

        printf("Melodia finalizada.\n");

    // Comando para desligar todos
    } else if (command_ == '0') {    
        turn_off_all();
        printf("Todos os LEDs e Buzzer desligados.\n");

    // Comando para ligar todos os LEDs
    } else if (command_ == '5') {    
        turn_on_all_leds();  // Liga todos os LEDs
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
            process_command(command); // Processar comando
        }
    }

    return 0;
}
