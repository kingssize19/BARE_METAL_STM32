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



























