#include <Arduino.h>

#define LED1 2
#define LED2 4
#define LED3 5

#define BOTAO1 15
#define BOTAO2 16

volatile int intervaloLED3 = 0;

void taskLED1(void *pvParameters) {
  while (true) {
    digitalWrite(LED1, !digitalRead(LED1));
    vTaskDelay(300 / portTICK_PERIOD_MS);
  }
}

void taskLED2(void *pvParameters) {
  while (true) {
    digitalWrite(LED2, !digitalRead(LED2));
    vTaskDelay(700 / portTICK_PERIOD_MS);
  }
}

void taskBotao1(void *pvParameters) {
  while (true) {
    if (digitalRead(BOTAO1) == LOW) {
      Serial.println("Botao 1 pressionado - LED3 em 500 ms");
      intervaloLED3 = 500;
      while (digitalRead(BOTAO1) == LOW) {
        vTaskDelay(20 / portTICK_PERIOD_MS);
      }
      vTaskDelay(80 / portTICK_PERIOD_MS);
    }
    vTaskDelay(20 / portTICK_PERIOD_MS);
  }
}

void taskBotao2(void *pvParameters) {
  while (true) {
    if (digitalRead(BOTAO2) == LOW) {
      Serial.println("Botao 2 pressionado - LED3 em 100 ms");
      intervaloLED3 = 100;
      while (digitalRead(BOTAO2) == LOW) {
        vTaskDelay(20 / portTICK_PERIOD_MS);
      }
      vTaskDelay(80 / portTICK_PERIOD_MS);
    }
    vTaskDelay(20 / portTICK_PERIOD_MS);
  }
}

void taskLED3(void *pvParameters) {
  while (true) {
    if (intervaloLED3 > 0) {
      digitalWrite(LED3, HIGH);
      vTaskDelay(intervaloLED3 / portTICK_PERIOD_MS);
      digitalWrite(LED3, LOW);
      intervaloLED3 = 0;
    }
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(BOTAO1, INPUT_PULLUP);
  pinMode(BOTAO2, INPUT_PULLUP);

  xTaskCreatePinnedToCore(taskLED1, "LED1", 2048, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(taskLED2, "LED2", 2048, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(taskBotao1, "BOTAO1", 2048, NULL, 2, NULL, 0);
  xTaskCreatePinnedToCore(taskBotao2, "BOTAO2", 2048, NULL, 2, NULL, 0);

  xTaskCreatePinnedToCore(taskLED3, "LED3", 2048, NULL, 1, NULL, 1);
}

void loop() {
}