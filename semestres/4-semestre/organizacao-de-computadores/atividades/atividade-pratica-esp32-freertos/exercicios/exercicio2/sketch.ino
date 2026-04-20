#include <Arduino.h>

#define LED1 2
#define LED2 4
#define LED3 5
#define LED4 18

#define BOTAO1 15
#define BOTAO2 16

volatile bool ligarLED3 = false;
volatile bool ligarLED4 = false;

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
      Serial.println("Botao 1 pressionado - ligar LED3");
      ligarLED3 = true;
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
      Serial.println("Botao 2 pressionado - LED4 pisca 3 vezes");
      ligarLED4 = true;
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
    if (ligarLED3) {
      digitalWrite(LED3, HIGH);
      vTaskDelay(500 / portTICK_PERIOD_MS);
      digitalWrite(LED3, LOW);
      ligarLED3 = false;
    }
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}

void taskLED4(void *pvParameters) {
  while (true) {
    if (ligarLED4) {
      for (int i = 0; i < 3; i++) {
        digitalWrite(LED4, HIGH);
        vTaskDelay(120 / portTICK_PERIOD_MS);
        digitalWrite(LED4, LOW);
        vTaskDelay(120 / portTICK_PERIOD_MS);
      }
      ligarLED4 = false;
    } else {
      digitalWrite(LED4, HIGH);
      vTaskDelay(1000 / portTICK_PERIOD_MS);
      digitalWrite(LED4, LOW);
      vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(BOTAO1, INPUT_PULLUP);
  pinMode(BOTAO2, INPUT_PULLUP);

  xTaskCreatePinnedToCore(taskLED1, "LED1", 2048, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(taskLED2, "LED2", 2048, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(taskBotao1, "BOTAO1", 2048, NULL, 2, NULL, 0);
  xTaskCreatePinnedToCore(taskBotao2, "BOTAO2", 2048, NULL, 2, NULL, 0);

  xTaskCreatePinnedToCore(taskLED3, "LED3", 2048, NULL, 1, NULL, 1);
  xTaskCreatePinnedToCore(taskLED4, "LED4", 2048, NULL, 1, NULL, 1);
}

void loop() {
}