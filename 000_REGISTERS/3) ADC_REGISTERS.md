# ADC (Analog-to-Digital Converter) Nedir?

* ADC (Analog-to-Digital Converter), analog sinyalleri dijital sinyallere dönüştüren bir elektronik bileşendir. Mikrodenetleyicilerde, sensörlerden gelen analog sinyalleri (örneğin sıcaklık, voltaj, basınç) dijital verilere dönüştürerek işlem yapabilmek için kullanılır.

# Resolution (Çözünürlük) Nedir?

* ADC'nin çözünürlüğü, analog sinyali dijitale dönüştürürken kullanılan bit sayısını ifade eder. Örneğin, 12-bit çözünürlüğe sahip bir ADC, analog sinyali 4096 (2^12) farklı dijital değere dönüştürebilir. Çözünürlük ne kadar yüksekse, dijitalleştirilmiş sinyalin hassasiyeti de o kadar artar.

# Step Size, VREF

* **Step Size :** ADC'nin dijital değerler arasındaki adım büyüklüğüdür. Step size, VREF (Referans Voltajı) ve çözünürlük (N bit) kullanılarak hesaplanır.

![image](https://github.com/user-attachments/assets/c60ad610-d7c0-4298-b584-74b887fae612)


* **VREF :** ADC'nin referans voltajıdır. Bu voltaj, ADC'nin ölçebileceği maksimum analog voltajı belirler. STM32F446RE'de VREF genellikle 3.3V'dur.

# Single Channel, Single Conversion Mode Nedir?

* **Single Channel :** ADC'nin sadece bir kanalı kullanarak analog sinyali dijitale dönüştürmesidir.
* **Single Conversion Mode :** ADC'nin sadece bir kez ölçüm yapması ve ardından durmasıdır. Bu modda, ADC bir tetikleme sinyali aldığında bir ölçüm yapar ve sonucu kaybeder.

# Multi Channel, Single Conversion Mode Nedir?

* **Multi Channel :** ADC'nin birden fazla kanalı kullanarak farklı analog sinyalleri dijitale dönüştürmesidir.
* **Single Conversion Mode :** Her kanal için sadece bir kez ölçüm yapılır. ADC, tüm kanalları sırayla tarar ve her birinden bir ölçüm alır.

# Single Channel Continuous Conversion Mode Nedir?

* **Single Channel Continuous Conversion Mode :** ADC'nin sürekli olarak tek bir kanaldan ölçüm yapmasıdır. ADC, bir ölçümü tamamladıktan hemen sonra yeni bir ölçüme başlar.

# Multi Channel Continuous Mode Nedir?

* Multi Channel Continuous Mode :** ADC'nin birden fazla kanalı sürekli olarak tarayarak ölçüm yapmasıdır. ADC, tüm kanalları sırayla tarar ve her birinden sürekli olarak ölçüm alır.

# Injected Continuous Conversion Mode Nedir?

* **Injected Continuous Conversion Mode :** Bu mod, normal (regular) kanalların yanı sıra, özel olarak tanımlanmış "injected" kanallar üzerinde sürekli ölçüm yapılmasını sağlar. Injected kanallar, normal kanallardan bağımsız olarak çalışır ve öncelikli olarak işlenebilir.

# Single ADC Konfigürasyonu Yapılırken Hangi Ayarların Yapılması Gerekir?

**1. Clock Ayarları :** ADC'nin çalışması için gerekli saat sinyalinin ayarlanması.
**2. Resolution Ayarlanması :** ADC'nin çözünürlüğünün belirlenmesi (örneğin, 12-bit, 10-bit, 8-bit).
**3. Sampling Time :** Örnekleme süresinin ayarlanması. Bu, ADC'nin analog sinyali örnekleme süresini belirler.
**4. Channel Seçimi :** Hangi kanalın kullanılacağının belirlenmesi.
**5. Conversion Mode :** Single conversion veya continuous conversion modunun seçilmesi.
**6. Trigger Ayarları :** ADC'nin tetikleme kaynağının belirlenmesi (örneğin, yazılımsal tetikleme veya harici tetikleme).
**7. Interrupt Ayarları :** Eğer gerekliyse, ADC dönüşümü tamamlandığında kesme (interrupt) oluşturulması.


# Çoklu ADC Kullanılırken Hangi Konfigürasyon Ayarları Yapılması Gerekir?

**1. Clock Ayarları :** Her ADC için saat sinyalinin ayarlanması.
**2. Resolution Ayarlanması :** Her ADC'nin çözünürlüğünün belirlenmesi.
**3. Sampling Time :** Her ADC için örnekleme süresinin ayarlanması.
**4. Channel Seçimi :** Her ADC için kullanılacak kanalların belirlenmesi.
**5. Conversion Mode :** Her ADC için single veya continuous conversion modunun seçilmesi.
**6. Trigger Ayarları :** Her ADC için tetikleme kaynağının belirlenmesi.
**7. Interrupt Ayarları :** Her ADC için kesme ayarlarının yapılması.
**8. DMA Ayarları :** Eğer kullanılacaksa, DMA (Direct Memory Access) ayarlarının yapılması. Bu, ADC verilerini doğrudan belleğe aktarmak için kullanılır.


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# ADC_TypeDef

```c
typedef struct
{
  __IO uint32_t SR;     /*!< ADC status register,                         Address offset: 0x00 */
  __IO uint32_t CR1;    /*!< ADC control register 1,                      Address offset: 0x04 */
  __IO uint32_t CR2;    /*!< ADC control register 2,                      Address offset: 0x08 */
  __IO uint32_t SMPR1;  /*!< ADC sample time register 1,                  Address offset: 0x0C */
  __IO uint32_t SMPR2;  /*!< ADC sample time register 2,                  Address offset: 0x10 */
  __IO uint32_t JOFR1;  /*!< ADC injected channel data offset register 1, Address offset: 0x14 */
  __IO uint32_t JOFR2;  /*!< ADC injected channel data offset register 2, Address offset: 0x18 */
  __IO uint32_t JOFR3;  /*!< ADC injected channel data offset register 3, Address offset: 0x1C */
  __IO uint32_t JOFR4;  /*!< ADC injected channel data offset register 4, Address offset: 0x20 */
  __IO uint32_t HTR;    /*!< ADC watchdog higher threshold register,      Address offset: 0x24 */
  __IO uint32_t LTR;    /*!< ADC watchdog lower threshold register,       Address offset: 0x28 */
  __IO uint32_t SQR1;   /*!< ADC regular sequence register 1,             Address offset: 0x2C */
  __IO uint32_t SQR2;   /*!< ADC regular sequence register 2,             Address offset: 0x30 */
  __IO uint32_t SQR3;   /*!< ADC regular sequence register 3,             Address offset: 0x34 */
  __IO uint32_t JSQR;   /*!< ADC injected sequence register,              Address offset: 0x38*/
  __IO uint32_t JDR1;   /*!< ADC injected data register 1,                Address offset: 0x3C */
  __IO uint32_t JDR2;   /*!< ADC injected data register 2,                Address offset: 0x40 */
  __IO uint32_t JDR3;   /*!< ADC injected data register 3,                Address offset: 0x44 */
  __IO uint32_t JDR4;   /*!< ADC injected data register 4,                Address offset: 0x48 */
  __IO uint32_t DR;     /*!< ADC regular data register,                   Address offset: 0x4C */
} ADC_TypeDef;
```

## 1. SR (Status Register) - Adres: 0x00

ADC'nin mevcut durumunu gösteren bir registerdır. Özellikle dönüşümlerin tamamlanıp tamamlanmadığını kontrol etmek için kullanılır.

* **EOC (End of Conversion) :** Regular (düzenli) dönüşümün tamamlandığını belirtir. Bu bit set edildiğinde, dönüşüm sonucu DR (Data Register) registerında okunabilir.
* **JEOC (Injected End of Conversion) :** Injected (enjekte edilmiş) dönüşümün tamamlandığını belirtir. Bu bit set edildiğinde, dönüşümün sonucu **JDR1**, **JDR2**, **JDR3** veya **JDR4** registerlarında okunabilir.
* **OVR (Overrun) :** Eğer yeni bir dönüşüm sonucu alınmadan önce önceki sonuç okunmamışsa bu bit set edilir.


## 2. CR1 (Control Register 1) - Adres: 0x04

ADC'nin çalışma modunu ve kesme ayarlarını kontrol eder.

* **RES (Resolution) :** ADC'nin çözünürlüğünü belirler (örneğin, 12-bit, 10-bit, 8-bit, 6-bit).
* **SCAN (Scan Mode) :** Multi-channel (çoklu kanal) modunu etkinleştirir. Bu modda ADC, birden fazla kanalı otomatik olarak tarar.
* **JEOCIE (Injected End of Conversion Interrupt Enable) :** Injected dönüşüm tamamlandığında kesme oluşturur.
* **EOCIE (End of Conversion Interrupt Enable) :** Regular dönüşüm tamamlandığında kesme oluşturur.

# 3. CR2 (Control Register 2) - Adres: 0x08

ADC'nin dönüşüm başlatma ve çalışma modu ayarlarını kontrol eder.

* **ADON (ADC On) :** ADC'yi etkinleştirir veya devre dışı bırakır.
* **CONT (Continuous Conversion) :** Sürekli dönüşüm modunu etkinleştirir. Bu modda ADC, bir dönüşümü tamamladıktan sonra otomatik olarak yeni bir dönüşüme başlar.
* **SWSTART (Start Conversion) :** Yazılımsal tetikleme ile regular dönüşümü başlatır.
* **EXTEN (External Trigger Enable) :** Harici tetikleme kaynağını etkinleştirir.
* **JSWSTART (Injected Start Conversion) :** Yazılımsal tetikleme ile injected dönüşümü başlatır.

# 4. SMPR1 (Sample Time Register 1) - Adres: 0x0C

ADC kanallarının örnekleme sürelerini belirler. Bu register, kanal 10'dan kanal 18'e kadar olan kanalların örnekleme sürelerini ayarlar.

* **SMPx (Sample Time for Channel x) :** Her kanal için örnekleme süresini belirler. Örnekleme süresi, ADC'nin analog sinyali örnekleme süresini belirler.

# 5. SMPR2 (Sample Time Register 2) - Adres: 0x10

ADC kanallarının örnekleme sürelerini belirler. Bu register, kanal 0'dan kanal 9'a kadar olan kanalların örnekleme sürelerini ayarlar.

* **SMPx (Sample Time for Channel x) :** Her kanal için örnekleme süresini belirler.

# 6. JOFR1, JOFR2, JOFR3, JOFR4 (Injected Channel Data Offset Registers) - Adres: 0x14, 0x18, 0x1C, 0x20

Injected kanallar için ofset değerlerini saklar. Bu ofset değerleri, dönüşüm sonuçlarından çıkarılır.

* **JOFRx (Injected Channel x Offset) :** Injected kanalın ofset değerini belirler.

# 7. HTR (Watchdog Higher Threshold Register) - Adres: 0x24

ADC watchdog üst eşik değerini belirler. Eğer dönüşüm sonucu bu değeri aşarsa, watchdog tetiklenir.

* **HT (Higher Threshold) :** Watchdog üst eşik değerini belirler.

# 8. LTR (Watchdog Lower Threshold Register) - Adres: 0x28

ADC watchdog alt eşik değerini belirler. Eğer dönüşüm sonucu bu değerin altına düşerse, watchdog tetiklenir.

* **LT (Lower Threshold) :** Watchdog alt eşik değerini belirler.

# 9. SQR1, SQR2, SQR3 (Regular Sequence Registers) - Adres: 0x2C, 0x30, 0x34

Regular dönüşüm sırasında hangi kanalların kullanılacağını ve sıralarını belirler.

**SQx (Sequence x) :** Regular dönüşüm sırasında kullanılacak kanal numarasını belirler.
* **L (Sequence Length) :** Regular dönüşüm sırasında kaç kanalın kullanılacağını belirler.

# 10. JSQR (Injected Sequence Register) - Adres: 0x38

Injected dönüşüm sırasında hangi kanalların kullanılacağını ve sıralarını belirler.

* **JSQx (Injected Sequence x) :** Injected dönüşüm sırasında kullanılacak kanal numarasını belirler.
* **JL (Injected Sequence Length) :** Injected dönüşüm sırasında kaç kanalın kullanılacağını belirler.

# 11. JDR1, JDR2, JDR3, JDR4 (Injected Data Registers) - Adres: 0x3C, 0x40, 0x44, 0x48

Injected dönüşüm sonuçlarını saklar.

* **JDATA (Injected Conversion Data) :** Injected dönüşüm sonucunu içerir.

# 12. DR (Regular Data Register) - Adres: 0x4C

Regular dönüşüm sonucunu saklar.

* **DATA (Regular Conversion Data) :** Regular dönüşüm sonucunu içerir.




























