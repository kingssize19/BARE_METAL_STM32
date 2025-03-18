# TIMERS (Zamanlayıcılar)

Zamanlayıcılar, mikrodenetleyicilerde zamanla ilgili işlemleri gerçekleştirmek için kullanılan donanım modülleridir. Bu modüller, belirli bir süre saymak, gecikmeler oluşturmak veya olaylar arasındaki zamanı ölçmek gibi işlevleri yerine getirir. 

STM32 mikrodenetleyicilerinde farklı türde zamanlayıcılar bulunur :
* Temel Zamanlayıcılar (Basic Timers)
* Genel Amaçlı Zamanlayıcılar (General-Purpose Timers)
* Gelişmiş Zamanlayıcılar (Advanced Timers)


## Timer Uses (Zamanlayıcı Kullanım Alanları)

Zamanlayıcıların başlıca kullanım alanları şunlardır :

**1. Counting Events (Olayları Sayma) :** Zamanlayıcılar, belirli olayların kaç kez gerçekleştiğini saymak için kullanılır. Örneğin, bir sensörden gelen sinyallerin sayısını ölçmek.
**2. Creating Delays (Gecikmeler Oluşturma) :** Zamanlayıcılar, belirli bir süre boyunca bekleme (delay) işlemi gerçekleştirmek için kullanılır. Örneğin, bir LED'in belirli aralıklarla yanıp sönmesini sağlamak.
**3. Measuring Time Between Events (Olaylar Arasındaki Zamanı Ölçmek) :** Zamanlayıcılar, iki olay arasında geçen süreyi ölçmek için kullanılır.Örneğin, bir butona basılma süresini ölçmek.

## Timer (Internal Clock Source) vs Counter (External Clock Source)

* **Timer (Zamanlayıcı) :** Zamanlayıcı, iç saat kaynağı (internal clock source) kullanır. Yani, mikrodenetleyicinin içindeki sistem saatini kullanarak zamanı sayar.
* **Counter (Sayaç) :** Sayaç, harici bir saat kaynağı (external clock source) kullanır. Örneğin, bir sensörden gelen sinyaller gibi harici bir kaynakla çalışır.

## Time Base Generator

* Zamanlayıcı, belirli zaman aralığında (time base) sinyaller üretmek için kullanılır. Bu, özellikle periyodik işlemler (örneğin, PWM sinyali üretme) için kullanışlıdır.

## Input Capture Mode (Giriş Yakalama Modu)

* Bu mod, harici bir olayın zamanını ölçmek için kullanılır. Örneğin, bir sinyalin yükselen veya düşen kenarının ne zaman gerçekleştiğini kaydeder. Bu, frekans ölçümü veya puls genişliği ölçümü gibi uygulamalarda kullanılır.

## Output Compare Mode (Çıkış Karşılaştırma Modu)

* Bu mod, zamanlayıcının belirli bir değere ulaştığında bir çıkış sinyali üretmesini sağlar. Örneğin, bir PWM sinyali oluşturmak veya bir LED'i belirli aralıklarla yakıp söndürmek için kullanılır.

## One Pulse Mode (Tek Darbe Modu)

* Bu mod, bir tetikleyici (trigger) sinyali aldıktan sonra programlanabilir bir gecikme ile tek bir darbe (pulse) üretir. Bu, özellikle tek seferlik zamanlama işlemleri için kullanışlıdır.

## Timer Count Register (Zamanlayıcı Sayma Kaydı)

* Bu kayıt (CNT), zamanlayıcının anlık sayma değerini tutar. Zamanlayıcı, bu değeri artırır veya azaltır. Kaydın boyutu, kullanılan zamanlayıcı türüne göre 16 bit veya 32 bit olabilir.

## Timer Auto-Reload Register (Zamanlayıcı Otomatik Yeniden Yükleme Kaydı)

* Bu kayıt (ARR), zamanlayıcının sayacağı maksimum değeri belirler. Zamanlayıcı, bu değere ulaştığında bir bayrak (flag) yükseltir ve sayma işlemi yeniden başlar. Bu, periyodik zamanlama işlemleri için kullanılır.

## Timer Prescaler Register (Zamanlayıcı Ön Bölücü Kaydı)

* Bu kayıt (PSC), zamanlayıcının saat hızını yavaşlatmak için kullanılır. Ön bölücü, sistem saat frekansını belirli bir değere böler. Bu, zamanlayıcının daha yavaş saymasını sağlar.

## Timer Clock Pre-scaling (Zamanlayıcı Saat Ön Bölme)

* Zamanlayıcının saat hızı, sistem saatinden ön bölücü (prescaler) kullanılarak ayarlanır. Örneğin, 16 MHz sistem saatini 16'ya bölerek 1 MHz'lik bir zamanlayıcı saat hızı elde edebilirsiniz.

## Update Event 

* Bu olay, zamanlayıcının sayma değeri (CNT) otomatik yeniden yükleme kaydındaki (ARR) değere ulaştığında gerçekleşir. Bu, bir zaman aşımı (timeout) veya periyodik bir işlemin tamamlandığını gösterir.

## Period

* Periyot, zamanlayıcının bir sayma döngüsünü tamamlaması için gereken süredir. Bu, otomatik yeniden yükleme kaydında (ARR) yazılan değerle belirlenir.

## Up Counter 

* Bu modda, zamanlayıcı sıfırdan başlar ve otomatik yeniden yükleme kaydındaki (ARR) değere kadar artar.

## Down Counter

* Bu modda, zamanlayıcı otomatik yeniden yükleme kaydındaki (ARR) değerden başlar ve sıfıra kadar azalır.

## Computing Update Event

* Güncelleme olayının ne sıklıkla gerçekleşeceği, aşağıdaki formülle hesaplanır :

![image](https://github.com/user-attachments/assets/c8c2bcbc-16e9-4606-bbe7-401442728556)


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# TIMER REGISTERS

## 1. Prescaler (PSC)

**Prescaler**, zamanlayıcının saat hızını bölerek, zamanlayıcıyı daha düşük bir frekansta çalıştırmak için kullanılır. Zamanlayıcı saat hızı genellikle sistem saatine bağlıdır. Prescaler, bu saat hızını böler ve böylece zamanlayıcı aralığını uzatır.

```c
TIM2->PSC = 1600 - 1;
```

* **TIM2->PSC :** **TIM2** zamanlayıcısının **Prescaler** kaydına erişimi sağlar. Bu örnekte, **1600 - 1**  olarak ayarlandığında, zamanlayıcı her 1600 sistem saat döngüsünde bir adım atar (başka bir deyişle, prescaler değeri 1599 olarak ayarlanmıştır.)
* Bu ayar, zamanlayıcıyı **1 MHz** gibi daha düşük bir hızda çalıştırmak için kullanılır (eğer sistem saati 1600 MHz ise).

## 2. Auto-Reload Register (ARR)

**Auto-Reload Register (ARR)**, zamanlayıcının tekrar etme değerini belirler. Zamanlayıcı, ARR değerine ulaşınca sıfırlanır ve yeniden başlar. Bu, zamanlayıcının belirli bir süre aralığında kesme yapmasını sağlar.

```c
TIM2->ARR = 10000;
```

* **TIM2->ARR :** TIM2 zamanlayıcısının **Auto-Reload Register** kaydına erişimi sağlar. Bu örnekte, zamanlayıcı her 10000 döngüde bir sıfırlanacaktır.
* Zamanlayıcı bir döngü sonunda 10000'e ulaştığında, sıfırlanıp yeniden başlar ve bu aralıkta bir kesme üretilebilir.

## 3. Control Register 1 (CR1)

**Control Register 1 (CR1)**, zamanlayıcının çalışma modunu ve temel ayarları kontrol eder. Bu register üzerinden zamanlayıcıyı başlatabilir veya durdurabilirsiniz.

```c
TIM2->CR1 = 1;  // Enable timer 2
```

* **TIM2->CR1 :** TIM2 zamanlayıcısının **Control Register 1** kaydına erişimi sağlar. Bu örnekte, CR1 kaydına 1 yazmak, zamanlayıcıyı etkinleştirir.
* Zamanlayıcıyı aktif hale getirmek için bu bit 1 yapılır. Eğer 0 yapılırsa, zamanlayıcı durur.

## 4. Status Register (SR)

**Status Register (SR)**, zamanlayıcının durumunu belirten bayrakları (flags) içerir. Bu bayraklar, zamanlayıcının olaylarını veya kesme durumlarını belirtir. Örneğin, zamanlayıcı bir güncelleme kesmesi (update interrupt) gerçekleştirdiğinde bir bayrak set edilebilir.

```c
TIM2->SR & 1;    // Check update interrupt flag
TIM2->SR &= ~1;  // Clear update interrupt flag
```

* **TIM2->SR & 1 :** Bu işlem, **update interrupt flag**'inin (güncelleme kesmesi bayrağı) durumunu kontrol eder. Eğer bayrak set edilirse (1), bu durumda bir kesme gerçekleşmiştir.
* **TIM2->SR &= ~1 :** Bu işlem, **update interrupt flag**'ini temizler (0 yapar). Yani, kesme bayrağını sıfırlar.

## 5. Capture/Compare Register (CCR1, CCR2, CCR3, CCR4)

**Capture/Compare Registers (CCR)** zamanlayıcı kanalındaki karşılaştırma ve yakalama işlemleri için kullanılır. Zamanlayıcılar, bu kayıtlara yazılarak bir karşılaştırma yapılabilir veya dış bir sinyali yakalayarak bir zaman damgası alınabilir.

```c
timestamp = TIM2->CCR1;  // Read capture value
```

* **TIM2->CCR1 :** TIM2 zamanlayıcısının **Capture/Compare Register 1** kaydına erişimi sağlar. Burada, kanal 1'in yakaladığı değeri okuyabilirsiniz. Bu değer, zamanlayıcı bir sinyalin kenarını (rising/falling edge) yakaladığında elde edilen zaman damgasıdır.

## 6. Capture Compare Mode Register 1 (CCMR1)

**Capture Compare Mode Register 1 (CCMR1)**, kanal1 ve kanal 2 için yakalama ve karşılaştırma fonksiyonlarını yapılandırır. Burada, kanalın hangi türde çalışacağı (input capture or output compare) belirlenebilir.

```c
TIM2->CCMR1 = 0x41;  // Set CH1 to capture at every edge
```

* **TIM2->CCMR1 = 0x41 :** Bu değer, kanal 1'in her iki kenarda da (hem yükselen hem de alçalan) yakalama yapmasını sağlar. 0x41, özel bir bit desenini ifade eder :
  * **0x40** bitini set etmek, kanalın her iki kenarda da çalışmasını sağlar (yükselen ve alçalan kenar).
  * **0x01** bitini set etmek, giriş sinyalini ölçmek için **"input capture"** modunu etkinleştirir.


## 7. Capture Compare Mode Register 2 (CCMR2)

**Capture Compare Mode Register 2 (CCMR2)**, kanal 3 ve kanal 4 için benzer yapılandırmayı sağlar. Burada da yaklama veya karşılaştırma fonksiyonları belirlenebilir.

## 8. Capture/Compare Enable Register (CCER)

**Capture/Compare Enable Register (CCER)**, her kanal için **input capture** veya **output compare** işlevlerini etkinleştirmek için kullanılır.

```c
TIM2->CCER = 1;  // Enable channel 1
```

* **TIM2->CCER :** Bu kayıt üzerinden kanal 1'i etkinleştirebilirsiniz. **1** yazmak, kanal 1'i aktive eder. Bu durumda kanal 1, ya dış bir sinyali yakalayacak ya da zamanlayıcıyla karşılaştırma yapacaktır.

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Özet 

* **PSC :** Zamanlayıcının hızını belirler.
* **ARR :** Zamanlayıcının döngüsünün bitiş değerini belirler.
* **CR1 :** Zamanlayıcıyı başlatma veya durdurma işlevini yerine getirir.
* **SR :** Zamanlayıcı durumunu kontrol etmek için kullanılır.
* **CCR :** Yakalama ve karşılaştırma için kullanılan kayıtlardır.
* **CCMR1/CCMR2 :** Kanalın işlevini belirler (giriş yakalama veya çıkış karşılaştırma).
* **CCER :** Kanal işlevini etkinleştiren kayıttır (yakalama/karşılaştırma).














