#include <stdio.h>
#include <string.h>
#include "esp_log.h"

#include "mbedtls/base64.h"

static const char* TAG = "base64";

void app_main(void)
{
    char* encode_input = "username:password";
    char* decode_input = "dXNlcm5hbWU6cGFzc3dvcmQ=";

    unsigned char output[64];
    size_t outlen;

    memset(output, 0, sizeof(output));

    mbedtls_base64_encode(output, 64, &outlen, (const unsigned char*)encode_input, strlen(encode_input));
    ESP_LOGI(TAG, "encode -> %s", output);

    memset(output, 0, sizeof(output));

    mbedtls_base64_decode(output, sizeof(output), &outlen, (const unsigned char*)decode_input, strlen(decode_input));
    ESP_LOGI(TAG, "decode -> %s", output);
}