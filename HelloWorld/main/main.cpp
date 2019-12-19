/**
This file is part of Test-TravisCI-and-ESP-IDF (https://github.com/CalinRadoni/Test-TravisCI-and-ESP-IDF)
Copyright (C) 2019+ by Calin Radoni

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_err.h"
#include "esp_log.h"

const char* TAG = "Test-HelloWorld";

extern "C" {
    void app_main()
    {
        esp_chip_info_t chip_info;
        esp_chip_info(&chip_info);

        ESP_LOGI(TAG, "ESP32 chip with %d cores, revision %d", chip_info.cores, chip_info.revision);

        for (uint8_t i = 60; i > 0; i--) {
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }

        esp_restart();
    }
}
