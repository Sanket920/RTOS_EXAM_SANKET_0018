#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>

BaseType_t Task1;
BaseType_t Task2;
BaseType_t Task3;
TaskHandle_t xHandle_1;
TaskHandle_t xHandle_2;
TaskHandle_t xHandle_3;

TimerHandle_t One_Shot;

void Task1(void *pvparameters)
{
    while(1)
    {
        printf("Task1 RUNNING\n");
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
}

void Task2(void *pvparameters)
{
    while(1)
    {
        printf("Task2 RUNNING\n");
        vTaskDelay(2000/ portTICK_PERIOD_MS);
    }
}


void Task3(void *pvparameters)
{
    while(1)
    {
        printf("Task3 RUNNING\n");
        vTaskDelay(5000/ portTICK_PERIOD_MS);
    }
}

void OneShotCallback( TimerHandle_t xTimer )
{
printf("Function is expired and One Shot is called\n");
}

void app_main()
{
    result=xTaskCreate(Task1, "Task1",2048,NULL,5,&xHandle_1);
    if(result==pdPASS)
    {
        printf("Task1 created\n");
    }
    result=xTaskCreate(Task2, "Task2",2048,NULL,6,&xHandle_2);
    if(result==pdPASS)
    {
        printf("Task2 created\n");
    }

    result=xTaskCreate(Task3, "Task3",2048,NULL,7,&xHandle_3);
    if(result==pdPASS)
    {
        printf("Task3 created\n");
    }

}
