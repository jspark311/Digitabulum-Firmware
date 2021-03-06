#
# Digitabulum-r2 via ESP32
#

#COMPONENT_ADD_INCLUDEDIRS := include
#COMPONENT_PRIV_INCLUDEDIRS := include/freertos

#CFLAGS +=

COMPONENT_ADD_INCLUDEDIRS := ../lib/ManuvrOS/ManuvrOS ../lib

CFLAGS += -DIDENTITY_STRING="Digitabulum"
CFLAGS += -DVERSION_STRING="0.0.1"
CFLAGS += -DHW_VERSION_STRING="2"
CFLAGS += -DPROTOCOL_MTU=3000
CFLAGS += -DPROTOCOL_VERSION="0.0.1"
CFLAGS += -DMANUVR_PLATFORM_TIMER_PERIOD_MS=10
CFLAGS += -D__MANUVR_ESP32

COMPONENT_OBJS := main-esp32.o
