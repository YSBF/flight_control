#define SX1276_FIFO 0x00

#define SX1276_OP_MODE 0x01

#define SX1276_OP_MODE__LONG_RANGE_MODE       (0x01 << 7)
#define SX1276_OP_MODE__ACCESS_SHARED_REG     (0x01 << 6)
#define SX1276_OP_MODE__LOW_FREQUENCY_MODE_ON (0x01 << 3)
#define SX1276_OP_MODE__MODE(x)               (((x) & 0x07) << 0)

#define SX1276_FR_MSB 0x06

#define SX1276_FR_MID 0x07

#define SX1276_FR_LSB 0x08

#define SX1276_PA_CONFIG 0x09

#define SX1276_PA_CONFIG__PA_SELECT       (0x01 << 7)
#define SX1276_PA_CONFIG__MAX_POWER(x)    (((x) & 0x07) << 4)
#define SX1276_PA_CONFIG__OUTPUT_POWER(x) (((x) & 0x0F) << 0)

#define SX1276_PA_RAMP 0x0A

#define SX1276_OCP 0x0B

#define SX1276_OCP__OCP_ON      (0x01 << 5)
#define SX1276_OCP__OCP_TRIM(x) (((x) & 0x1F) << 0)

#define SX1276_LNA 0x0C

#define SX1276_LNA__LNA_GAIN(x)     (((x) & 0x07) << 5)
#define SX1276_LNA__LNA_BOOST_LF(x) (((x) & 0x03) << 3)
#define SX1276_LNA__LNA_BOOST_HF(x) (((x) & 0x03) << 0)

#define SX1276_FIFO_ADDR_PTR 0x0D

#define SX1276_FIFO_TX_BASE_ADDR 0x0E

#define SX1276_FIFO_RX_BASE_ADDR 0x0F

#define SX1276_FIFO_RX_CURRENT_ADDR 0x10

#define SX1276_IRQ_FLAGS_MASK 0x11

#define SX1276_IRQ_FLAGS_MASK__RX_TIMEOUT_MASK          (0x01 << 7)
#define SX1276_IRQ_FLAGS_MASK__RX_DONE_MASK             (0x01 << 6)
#define SX1276_IRQ_FLAGS_MASK__PAYLOAD_CRC_ERROR_MASK   (0x01 << 5)
#define SX1276_IRQ_FLAGS_MASK__VALID_HEADER_MASK        (0x01 << 4)
#define SX1276_IRQ_FLAGS_MASK__TX_DONE_MASK             (0x01 << 3)
#define SX1276_IRQ_FLAGS_MASK__CAD_DONE_MASK            (0x01 << 2)
#define SX1276_IRQ_FLAGS_MASK__FHSS_CHANGE_CHANNEL_MASK (0x01 << 1)
#define SX1276_IRQ_FLAGS_MASK__CAD_DETECTED_MASK        (0x01 << 0)

#define SX1276_IRQ_FLAGS 0x12

#define SX1276_IRQ_FLAGS__RX_TIMEOUT          (0x01 << 7)
#define SX1276_IRQ_FLAGS__RX_DONE             (0x01 << 6)
#define SX1276_IRQ_FLAGS__PAYLOAD_CRC_ERROR   (0x01 << 5)
#define SX1276_IRQ_FLAGS__VALID_HEADER        (0x01 << 4)
#define SX1276_IRQ_FLAGS__TX_DONE             (0x01 << 3)
#define SX1276_IRQ_FLAGS__CAD_DONE            (0x01 << 2)
#define SX1276_IRQ_FLAGS__FHSS_CHANGE_CHANNEL (0x01 << 1)
#define SX1276_IRQ_FLAGS__CAD_DETECTED        (0x01 << 0)

#define SX1276_RX_NB_BYTES 0x13

#define SX1276_RX_HEADER_CNT_VALUE_MSB 0x14

#define SX1276_RX_HEADER_CNT_VALUE_LSB 0x15

#define SX1276_RX_PACKET_CNT_VALUE_MSB 0x16

#define SX1276_RX_PACKET_CNT_VALUE_LSB 0x17

#define SX1276_MODEM_STAT 0x18

#define SX1276_MODEM_STAT__RX_CODING_RATE(x) (((x) & 0x07) << 5)
#define SX1276_MODEM_STAT__MODEM_STATUS(x)   (((x) & 0x1F) << 0)

#define SX1276_PKT_SNR_VALUE 0x19

#define SX1276_PKT_RSSI_VALUE 0x1A

#define SX1276_RSSI_VALUE 0x1B

#define SX1276_HOP_CHANNEL 0x1C

#define SX1276_HOP_CHANNEL__PLL_TIMEOUT             (0x01 << 7)
#define SX1276_HOP_CHANNEL__CRC_ON_PAYLOAD          (0x01 << 6)
#define SX1276_HOP_CHANNEL__FHSS_PRESENT_CHANNEL(x) (((x) & 0x3F) << 0)

#define SX1276_MODEM_CONFIG_1 0x1D

#define SX1276_MODEM_CONFIG_1__BW(x)                   (((x) & 0x0F) << 4)
#define SX1276_MODEM_CONFIG_1__CODING_RATE(x)          (((x) & 0x07) << 1)
#define SX1276_MODEM_CONFIG_1__IMPLICIT_HEADER_MODE_ON (0x01 << 0)

#define SX1276_MODEM_CONFIG_2 0x1E

#define SX1276_MODEM_CONFIG_2__SPREADING_FACTOR(x) (((x) & 0x0F) << 4)
#define SX1276_MODEM_CONFIG_2__TX_CONTINUOUS_MODE  (0x01 << 3)
#define SX1276_MODEM_CONFIG_2__RX_PAYLOAD_CRC_ON   (0x01 << 2)
#define SX1276_MODEM_CONFIG_2__SYMB_TIMEOUT_MSB(x) (((x) & 0x03) << 0)

#define SX1276_SYMB_TIMEOUT_LSB 0x1F

#define SX1276_PREAMBLE_MSB 0x20

#define SX1276_PREAMBLE_LSB 0x21

#define SX1276_PAYLOAD_LENGTH 0x22

#define SX1276_MAX_PAYLOAD_LENGTH 0x23

#define SX1276_HOP_PERIOD 0x24

#define SX1276_FIFO_RX_BYTE_ADDR 0x25

#define SX1276_MODEM_CONFIG_3 0x26

#define SX1276_MODEM_CONFIG_3__LOW_DATA_RATE_OPTIMIZE (0x01 << 3)
#define SX1276_MODEM_CONFIG_3__AGC_AUTO_ON            (0x01 << 2)

#define SX1276_PPM_CORRECTION 0x27

#define SX1276_FEI_MSB 0x28

#define SX1276_FEI_MIB 0x29

#define SX1276_FEI_LSB 0x2A

#define SX1276_RSSI_WIDEBAND 0x2C

#define SX1276_DETECT_OPTIMIZE 0x31

#define SX1276_INVERT_IQ 0x33

#define SX1276_INVERT_IQ__INVERT_IQ (0x01 << 6)

#define SX1276_DIO_MAPPING_1 0x40

#define SX1276_DIO_MAPPING_1__DIO0_MAPPING(x) (((x) & 0x3) << 6)
#define SX1276_DIO_MAPPING_1__DIO1_MAPPING(x) (((x) & 0x3) << 4)
#define SX1276_DIO_MAPPING_1__DIO2_MAPPING(x) (((x) & 0x3) << 2)
#define SX1276_DIO_MAPPING_1__DIO3_MAPPING(x) (((x) & 0x3) << 0)
