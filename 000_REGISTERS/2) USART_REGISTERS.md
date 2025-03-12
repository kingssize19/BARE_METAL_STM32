## UART (Universal Asynchronous Receiver/Transmitter)

* Seri iletişim protokolüdür. Verileri asenkron olarak (saat sinyali olmadan) iletir. TX (Transmit) ve RX (Receive) hatları üzerinden veri alışverişi yapar.

## USART (Universal Synchronous/Asynchronous Receiver/Transmitter)

* UART'ın gelişmiş halidir. Hem asenkron hem de senkron iletişimi destekler. Senkron iletişimde saat sinyali (clock) kullanılır.

## Duplex

* İletişim kanalının çift yönlü olup olmadığını belirtir. İki türü vardır :
  * **Half Duplex :** Aynı anda sadece bir yönde iletişim sağlar.
  * **Full Duplex :** Aynı anda iki yönde iletişim sağlar.

## Simplex

* İletişim kanalının tek yönlü olduğunu belirtir. Veri sadece bir yönde iletilir (örn : radyo yayını).

## Frame

* Seri iletişimde gönderilen veri paketidir. Başlangıç biti, veri bitleri, parity biti ve stop bitinden oluşur.

## Baudrate

* Saniyede iletilen bit sayısıdır. Birimi "bps" (bit per second) olarak ifade edilir. İletişim hızını belirler.

## Stop Bit

* Veri çerçevesinin (frame) sonunu belirtir. Genellikle 1 veya 2 bit uzunluğundadır.

## Parity

* Veri iletimi sırasında hata tespiti için kullanılır. Parity biti, veri bitlerindeki "1" sayısının çift veya tek olmasını kontrol eder.
* **Türleri :** Even Parity (çift), Odd Parity (tek), No parity (parity yok).

## Mode

* İletişim modunu belirtir. Örneğin :
  * **Asenkron Mod :** Saat sinyali olmadan iletişim.
  * **Senkron Mod  :** Saat sinyali ile iletişim.

## Word Length

* Bir seferde iletilen veri bitlerinin sayısıdır. Genellikle 5, 6, 7, 8 veya 9 bit olabilir.

## Hardware Flow Control

* Veri akışını kontrol etmek için donanımsal sinyaller kullanılır. Örneğin :
  * **RTS (Request to Send) :** Alıcının hazır olduğunu belirtir.
  * **CTS (Clear to Send) :** Veri göndermeye izin verir.


-----------------------------------------------------------------------------------------------------------------------------------------------------------

```c
typedef struct
{
  __IO uint32_t SR;         /*!< USART Status register,                   Address offset: 0x00 */
  __IO uint32_t DR;         /*!< USART Data register,                     Address offset: 0x04 */
  __IO uint32_t BRR;        /*!< USART Baud rate register,                Address offset: 0x08 */
  __IO uint32_t CR1;        /*!< USART Control register 1,                Address offset: 0x0C */
  __IO uint32_t CR2;        /*!< USART Control register 2,                Address offset: 0x10 */
  __IO uint32_t CR3;        /*!< USART Control register 3,                Address offset: 0x14 */
  __IO uint32_t GTPR;       /*!< USART Guard time and prescaler register, Address offset: 0x18 */
} USART_TypeDef;
```

### 1. SR (Status Register) - Durum Registerı (0x00)

* Bu register, USART modülünün durum bilgilerini tutar. Örneğin, veri alındı mı, veri gönderildi mi, hata oluştu mu gibi bilgiler bu registerda bulunur.
* **Önemli Bitler :**
  * **RXNE (Receive Data Register Not Empty) :** Alınan veri registerda hazır olduğunda bu bit set edilir.
  * **TXE (Transmit Data Register Empty) :** Gönderilecek veri registerı boş olduğunda bu bit set edilir.
  * **TC (Transmission Complete) :** Veri gönderme işlemi tamamlandığında bu bit set edilir.

### 2. DR (Data Register) - Veri Registerı (0x04)

* Bu register, alınan veya gönderilecek veriyi tutar. RX (Receive) işlemi sırasında bu registerdan veri okunur, TX (Transmit) işlemi sırasında bu registera veri yazılır.

### 3. BRR (Baud Rate Register) - Baud Oranı Registerı (0x08)

* Bu register, USART iletişiminin baud oranını belirler. Baud oranı, iletişim hızını belirler ve bu registera yazılan değer, sistem saat frekansına göre hesaplanır. 

```c
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate)
{
	return ((PeriphClk + (BaudRate/2U)) / BaudRate);
}

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate)
{
	USARTx->BRR = compute_uart_bd(PeriphClk, BaudRate);
}

/* Configure baudrate */
uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);
```

### 4. CR1 (Control Register 1) - Kontrol Registerı 1 (0x0C)

* Bu register, USART modülünün temel kontrol ayarlarını yapmak için kullanılır.
* **Önemli Bitler :**
  * **UE (USART ENABLE) :** USART modülünü etkinleştirir.
  * **TE (Transmitter Enable) :** Veri gönderme işlemini etkinleştirir.
  * **RE (Receiver Enable) :** Veri alma işlemini etkinleştirir.
  * **RXNEIE (RX Not Empty Interrupt Enable) :** RXNE biti set edildiğinde kesme oluşturur.

### 5. CR2 (Control Register 2) - Kontrol Registerı 2 (0x10)

* Bu register, USART modülünün daha gelişmiş kontrol ayarlarını yapmak için kullanılır.
* **Önemli Bitler :**
  * **STOP (Stop Bits) :** Stop bit sayısını belirler (1 veya 2 bit).
  * **CLKEN (Clock Enable) :** Senkron modda saat sinyalini etkinleştirir.

### 6. CR3 (Control Register 3) - Kontrol Registerı 3 (0x14)

* Bu register, USART modülünün ek kontrol ayarlarını yapmak için kullanılır.
* **Önemli Bitler :**
  * **DMAT (DMA Enable Transmitter) :** DMA kullanarak veri göndermeyi etkinleştirir.
  * **DMAR (DMA Enable Receiver) :** DMA kullanarak veri almayı etkinleştirir.

### 7. GTPR (Guard Time and Prescaler Register) - Koruma Süresi ve Prescaler Registerı (0x18)

* Bu register, USART modülünün koruma süresi ve prescaler değerlerini ayarlamak için kullanılır. Genellikle özel durumlarda kullanılır.


## RX ve TX İşlemleri

### 1. RX (Veri Alma)

* Veri almak için önce **CR1** registerındaki **RE** biti set edilir.
* Veri geldiğinde **SR** registerındaki **RXNE** biti set edilir. Bu bit kontrol edilerek **DR** registerından veri okunur.

```c
while (!(USART1->SR & USART_SR_RXNE)); // RXNE biti set olana kadar bekle
uint8_t data = USART1->DR; // Veriyi oku
```

### 2. TX (Veri Gönderme)

* Veri Göndermek için önce **CR1** registerındaki **TE** biti set edilir.
* Veri göndermek için **SR** registerındaki **TXE** biti kontrol edilir. Bu bit set edildiğinde **DR** registerına veri yazılır.

```c
while (!(USART1->SR & USART_SR_TXE)); // TXE biti set olana kadar bekle
USART1->DR = data; // Veriyi gönder
```














