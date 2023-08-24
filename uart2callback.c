/*
 * Copyright (c) 2020, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== uart2callback.c ========
 */
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

/* POSIX Header files */
#include <semaphore.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/UART2.h>

/* Driver configuration */
#include "ti_drivers_config.h"

static sem_t sem;
static volatile size_t numBytesRead;
int count = 0;
int i;
char str[100];
char data[100];
char data_standark[100];

/*
 *  ======== callbackFxn ========
 */
        char *ptr;
        char first[20];
        char delay[20];
unsigned int time_delay;
void callbackFxn(UART2_Handle handle, void *buffer, size_t count, void *userArg, int_fast16_t status)
{
    if (status != UART2_STATUS_SUCCESS)
    {
        /* RX error occured in UART2_read() */
        while (1) {}
    }
      strcpy(data,buffer);
      if(data[strlen(data) - 1] == '@'){
          for(i = 0 ; i < strlen(data);i++){
              if(data[i] == '$' || data[i] == '@'){
                  data[i] = '\0';
              }

          }
          UART2_write(handle, data,strlen(data), NULL);
          strcpy(data_standark,data);
              ptr = strtok(data_standark," ");
              strcpy(first,ptr);
              ptr = strtok(NULL,".");
              strcpy(delay,ptr);

      }
      UART2_read(handle, (void*)str, 20, NULL);
}

    void callbackTxn(UART2_Handle handle, void *buffer, size_t count, void *userArg, int_fast16_t status)
    {
        if (status != UART2_STATUS_SUCCESS)
        {
            /* RX error occured in UART2_read() */
            while (1) {}
        }

        for( i = 0 ; i < strlen(data);i++){
            data[i] = '$';
        }
//        count = 0;
//        for(i = 0; i < strlen(str); i++){
//            str[i] = '$';
//        }
    }



//    numBytesRead = count;
//    sem_post(&sem);

/*
 *  ======== mainThread ========
 */

void *mainThread(void *arg0)
{

    const char echoPrompt[] = "Echoing characters:\r\n";
    UART2_Handle uart;
    UART2_Params uartParams;
    int32_t semStatus;
    uint32_t status = UART2_STATUS_SUCCESS;

    /* Call driver init functions */
    GPIO_init();

    /* Configure the LED pin */
    GPIO_setConfig(CONFIG_GPIO_LED_0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);

    /* Create semaphore */
//    semStatus = sem_init(&sem, 0, 0);

//    if (semStatus != 0)
//    {
//        /* Error creating semaphore */
//        while (1) {}
//    }

    /* Create a UART in CALLBACK read mode */
    UART2_Params_init(&uartParams);
    uartParams.readMode     = UART2_Mode_CALLBACK;
    uartParams.readCallback = callbackFxn;
    uartParams.baudRate     = 115200;
    uartParams.writeMode = UART2_Mode_CALLBACK;
    uartParams.writeCallback = callbackTxn;

    uart = UART2_open(CONFIG_UART2_0, &uartParams);

    if (uart == NULL)
    {
        /* UART2_open() failed */
        while (1){}
    }
    /* Turn on user LED to indicate successful initialization */
    GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_ON);
    /* Pass NULL for bytesWritten since it's not used in this example */
//    UART2_write(uart, echoPrompt, sizeof(echoPrompt), NULL);
    UART2_read(uart,(void*) str, 20,NULL);
//    data[count_num] = input;
//    count_num++;

    /* Loop forever echoing */
    while (1)
    {
     time_delay = atoi(delay);
     GPIO_toggle(CONFIG_GPIO_LED_0);
     usleep(time_delay*1000);


//        numBytesRead = 0;
//
//        /* Pass NULL for bytesRead since it's not used in this example */
//        status = UART2_read(uart, &input, 1, NULL);
//
//        if (status != UART2_STATUS_SUCCESS)
//        {
//            /* UART2_read() failed */
//            while (1) {}
//        }
//
//        /* Do not write until read callback executes */
//        sem_wait(&sem);
//
//        if (numBytesRead > 0)
//        {
//            status = UART2_write(uart, &input, 1, NULL);
//
//            if (status != UART2_STATUS_SUCCESS)
//            {
//                /* UART2_write() failed */
//                while (1) {}
//            }
//        }
//        if(data[count_num] == '@'){
//            count_num = 0;
//             UART2_write(uart, data, strlen(data), NULL);
//        }
    }
}
