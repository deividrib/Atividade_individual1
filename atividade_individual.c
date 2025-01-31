#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "pico/time.h"

#include "pio_matrix.pio.h"
#include "include/matriz_led_control.h"
#include "include/animacoesnumero.h"

#define OUT_PIN 7
#define LED_R_PIN 13

#define BUTTON1 5
#define BUTTON2 6

#define DEBOUNCE_TIME 300000  // 300 ms de debounce

// Variáveis globais
volatile int numero_atual = 0;
static volatile uint32_t last_time_button1 = 0;
static volatile uint32_t last_time_button2 = 0;

pio_t meu_pio = {
    .pio = pio0,
    .ok = false,
    .i = 0,
    .r = 0.0,
    .g = 0.0,
    .b = 0.0,
    .sm = 0
};

// Exibe o número na matriz de LEDs
void atualizar_matriz_led() {
    printf("Atualizando matriz para: %d\n", numero_atual);

    switch (numero_atual) {
        case 0: desenho_pio(numero0, &meu_pio); break;
        case 1: desenho_pio(numero1, &meu_pio); break;
        case 2: desenho_pio(numero2, &meu_pio); break;
        case 3: desenho_pio(numero3, &meu_pio); break;
        case 4: desenho_pio(numero4, &meu_pio); break;
        case 5: desenho_pio(numero5, &meu_pio); break;
        case 6: desenho_pio(numero6, &meu_pio); break;
        case 7: desenho_pio(numero7, &meu_pio); break;
        case 8: desenho_pio(numero8, &meu_pio); break;
        case 9: desenho_pio(numero9, &meu_pio); break;
        default: break;
    }
}

// Função de interrupção com debounce baseado no tempo
void gpio_irq_handler(uint gpio, uint32_t events) {
    uint32_t current_time = to_us_since_boot(get_absolute_time());

    if (gpio == BUTTON1) {
        if (current_time - last_time_button1 > DEBOUNCE_TIME) { // Debounce
            last_time_button1 = current_time;
            if (numero_atual < 9) numero_atual++;
            printf("Botão 1 pressionado. Número atual: %d\n", numero_atual);
            atualizar_matriz_led();
        }
    } else if (gpio == BUTTON2) {
        if (current_time - last_time_button2 > DEBOUNCE_TIME) { // Debounce
            last_time_button2 = current_time;
            if (numero_atual > 0) numero_atual--;
            printf("Botão 2 pressionado. Número atual: %d\n", numero_atual);
            atualizar_matriz_led();
        }
    }
}

int main() { 
    stdio_init_all();
    sleep_ms(2000);

    printf("Iniciando programa...\n");

    init_pio_routine(&meu_pio, OUT_PIN);
    atualizar_matriz_led();

    // Configuração do LED indicador
    gpio_init(LED_R_PIN);
    gpio_set_dir(LED_R_PIN, GPIO_OUT);

    // Configuração dos botões
    gpio_init(BUTTON1);
    gpio_set_dir(BUTTON1, GPIO_IN);
    gpio_pull_up(BUTTON1);

    gpio_init(BUTTON2);
    gpio_set_dir(BUTTON2, GPIO_IN);
    gpio_pull_up(BUTTON2);

    // Configuração das interrupções dos botões
    gpio_set_irq_enabled_with_callback(BUTTON1, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(BUTTON2, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

    while (true) {
        // Faz o LED vermelho piscar 5 vezes por segundo (100ms ligado, 100ms desligado)
        gpio_put(LED_R_PIN, 1);
        sleep_ms(100);
        gpio_put(LED_R_PIN, 0);
        sleep_ms(100);
    }

    return 0;
}
