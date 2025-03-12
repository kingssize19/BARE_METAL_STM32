```c
typedef struct {

	__IO uint32_t MODER;     /*!< GPIO port mode register,	Address offset : 0x00               */
	__IO uint32_t OTYPER;    /*!< GPIO port output type register,	Address offset : 0x04         */
	__IO uint32_t OSPEEDR;   /*!< GPIO port output speed register, 	Address offset : 0x08       */
	__IO uint32_t PUPDR;     /*!< GPIO port pull-up/pull-down register, Address offset : 0x0C   */
	__IO uint32_t IDR;       /*!< GPIO port input data register,	Address offset : 0x10         */
	__IO uint32_t ODR;       /*!< GPIO port output data register,	Address offset : 0x14         */
	__IO uint32_t BSRR;      /*!< GPIO port bit set/reset register,	Address offset : 0x18       */
	__IO uint32_t LCKR;      /*!< GPIO port configuration lock register, Address offset : 0x1C  */
	__IO uint32_t AFR[2];    /*!< GPIO alternate function registers, Address offset : 0x20-0x24 */

}GPIO_TypeDef;
```

### 1. MODER (GPIO Port Mode Register)

* **Addres offset :** 0x00;
* **Açıklama :** Bu register, GPIO pinlerinin çalışma modunu belirler. Her bir pin için 2 bitlik bir alaan bulunur ve bu alanlar pinin giriş, çıkış, alternatif fonksiyon veya analog modda çalışmasını sağlar.
* **Bit Alanları :**
  * **00 :** Giriş modu (Reset durumu)
  * **01 :** Genele amaçlı çıkış modu
  * **10 :** Alternatif fonksiyon modu
  * **11 :** Analog mod

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

### 2. OTYPER (GPIO Port Output Type Register)

* **Addres offset :** 0x04
* **Açıklama :** Bu register, GPIO pinlerinin çıkış tipini belirler. Her bir pin için 1 bitlik bir alaan bulunur ve bu alanlar pinin push-pull veya open-drain olarak çalışmasını sağlar.
* **Bit Alanları :**
  * **0 :** Push-pull (Reset durumu)
  * **1 :** Open-drain


----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

### 3. OSPEEDR (GPIO Port Output Speed Register)

* **Address offset :** 0x08
* **Açıklama :** Bu register, GPIO pinlerinin çıkış hızını belirler. Her bir pin için 2 bitlik bir alan bulunur ve bu alanlar pinin çıkış hızını ayarlar.
* **Bit Alanları :**
  * **00 :** Düşük hız
  * **01 :** Orta hız
  * **10 :** Yüksek hız
  * **11 :** Çok yüksek hız

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

### 4. PUPDR (GPIO Port Pull-Up/Pull-Down Register)

* **Address offset :** 0x0C
* **Açıklama :** Bu register, GPIO pinlerinin pull-up veya pull-down dirençlerini etkinleştirir veya devre dışı bırakır. Her bir pin için 2 bitlik bir alan bulunur.
* **Bit Alanları :**
  * **00 :** Pull-up veya pull-down yok (Reset durumu)
  * **01 :** Pull-up etkin
  * **10 :** Pull-down etkin
  * **11 :** Rezerve

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

### 5. IDR (GPIO Port Input Data Register)

* **Address offset :** 0x10
* **Açıklama :** Bu register, GPIO pinlerinin giriş durumunu okumak için kullanılır. Her bir pin için 1 bitlik bir alan bulunur ve bu alanlar pinin giriş durumunu (0 veya 1) gösterir.
* **Bit Alanları :**
  * **0 :** Giriş seviyesi düşük (0V)
  * **1 :** Giriş seviyesi yüksek (VDD)

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

### 6. ODR (GPIO Port Output Data Register)

* **Address offset :** 0x14
* **Açıklama :** Bu register, GPIO pinlerinin çıkış durumunu ayarlamak için kullanılır. Her bir pin için 1 bitlik bir alan bulunur ve bu alanlar pinin çıkış durumunu (0 veya 1) belirler.
* **Bit Alanları :**
  * **0 :** Giriş seviyesi düşük (0V)
  * **1 :** Giriş seviyesi yüksek (VDD)


----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

### 7. BSRR (GPIO Port Bit Set/Reset Register)

* **Address offset :** 0x18
* **Açıklama :** Bu register, GPIO pinlerinin çıkış durumunu atomik olarak ayarlamak veya sıfırlamak için kullanılır. 32 bitlik bir registerdır ve 16 biti set (1 yapma), 16 biti reset (0 yapma) işlemleri için kullanılır.
* **Bit Alanları :**
  * **0-15  :** Set bitleri (BS0 - BS15)
  * **16-31 :** Reset bitleri (BR0 - BR15)

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

### 8. LCKR (GPIO Port Configuration Lock Register)

* **Address offset :** 0x1C
* **Açıklama :** Bu register, GPIO pinlerinin konfigürasyonunu kilitlemek için kullanılır. Kilitleme işlemi yapıldıktan sonra, pinlerin mod, tip, hız ve pull-up/pull-down ayarları değiştirilemez.
* **Bit Alanları :**
  * **0-15 :** Kilitleme bitleri (LCK0 - LCK15)
  * **16 :** Kilitleme anahtarı (LCKK)

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

### 9. AFR\[2\] (GPIO Alternate Function Registers)

* **Address offset :** 0x20-0x24
* **Açıklama :** Bu registerlar, GPIO pinlerinin alternatif fonksiyonlarını seçmek için kullanılır. Her bir pin için 4 bitlik bir alan bulunur ve bu alanlar pinin hangi alternatif fonksiyonu kullanacağını belirler.
* **Bit Alanları :**
  * **AFR\[0\] :** Pin 0-7 için alternatif fonksiyon seçimi
  * **AFR\[1\] :** Pin 8-15 için alternatif fonksiyon seçimi



----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

**Bu registerlar, mikrodenetleyicinin GPIO pinlerini yapılandırmak ve kontrol etmek için kullanılır. Her bir register, farklı bir işlevi yerine getirir ve bu işlevler, mikrodenetleyicinin giriş/çıkış işlemlerini yönetmek için kritik öneme sahiptir.**























