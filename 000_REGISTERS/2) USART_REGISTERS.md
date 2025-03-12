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

### 1. SR (Status Register) - Durum Register'ı (0x00)

* Bu register, USART modülünün durum bilgilerini tutar. Örneğin, veri alındı mı, veri gönderildi mi, hata oluştu mu gibi bilgiler bu registerda bulunur.
* **Önemli Bitler :**
  * **RXNE (Receive Data Register Not Empty) :** Alınan veri registerda hazır olduğunda bu bit set edilir.
  * **TXE (Transmit Data Register Empty) :** Gönderilecek veri registerı boş olduğunda bu bit set edilir.
  * **TC (Transmission Complete) :** Veri gönderme işlemi tamamlandığında bu bit set edilir.




















