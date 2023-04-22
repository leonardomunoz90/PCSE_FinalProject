# PCSE_FinalProject

Repositorio de Leonardo Agustín Muñoz para el proyecto final de PCSE y PdM

Consiste un driver para el sensor de temperatura y humedad SHT31 utilizando una placa nucleo STM32G031.
Para esto se implementó una máquina de estados finitos encargada del muestreo periodico y los tiempos de espera del sensor 

Los módulos de software utilizados son:
- API_delay: Código del delay no bloqueante
- API_FSM : Código de máquina de estados con su definición de variables y typedef
- API_sht31: Contiene la dirección y comandos posibles de ser enviados al sensor para la medicion de temperatura y humedad 
- ports.c: Contiene los wrappers de las funciones de HAL para dar portabilidad entre plataformas

Documentos de refencia:
- Hoja de datos del sensor : https://sensirion.com/media/documents/213E6A3B/63A5A569/Datasheet_SHT3x_DIS.pdf
- Hoja de datos del microcontrolador: https://www.st.com/resource/en/datasheet/stm32g031j6.pdf
