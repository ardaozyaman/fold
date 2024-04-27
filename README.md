1. **Eğitim Fonksiyonu:**
   Eğitim fonksiyonu, destek vektör makinelerini eğitmek için kullanılır. Bu fonksiyon, verilen eğitim veri setiyle birlikte destek vektör makinesinin parametrelerini öğrenir. Matematiksel olarak, eğitim süreci aşağıdaki adımları içerir:

   a. Çekirdek matrisini hesapla:
      \[ K_{ij} = \exp(-\gamma ||x_i - x_j||^2) \]
   
   b. Alpha (α) vektörlerini güncelle:
      \[ \alpha_i = \alpha_i + \eta \]
      \[ b = b + \eta y_i \]

   Burada:
   - \( x_i \) ve \( x_j \) eğitim veri setindeki i ve j indisli örneklerdir.
   - \( \gamma \) RBF çekirdeği için bir hiperparametredir.
   - \( \alpha_i \) destek vektörlerinin katsayılarıdır.
   - \( \eta \) öğrenme hızıdır.
   - \( y_i \) eğitim veri setindeki i indisli örneğin sınıf etiketidir.

2. **Tahmin Fonksiyonu:**
   Tahmin fonksiyonu, eğitilmiş destek vektör makinesi kullanılarak yeni veri noktalarının sınıflandırılması için kullanılır. Bu fonksiyon, verilen bir veri noktasının sınıfını tahmin eder. Matematiksel olarak, tahmin süreci şu şekilde yapılır:
   
   \[ f(x) = b + \sum_{i=1}^{n_{\text{SV}}} \alpha_i y_i K(x, x_i) \]
   \[ \text{Tahmin}(x) = \text{sgn}(f(x)) \]

   Burada:
   - \( f(x) \) verilen veri noktasının karar fonksiyonudur.
   - \( b \) yanlılık terimidir.
   - \( \alpha_i \) destek vektörlerinin katsayılarıdır.
   - \( y_i \) destek vektörlerinin sınıf etiketleridir.
   - \( K(x, x_i) \) RBF çekirdeği değeridir.
   - \( \text{sgn} \) işareti belirtir.

3. **RBF (Gaussian) Çekirdeği:**
   RBF çekirdeği, iki veri noktası arasındaki benzerliği ölçmek için kullanılır. Matematiksel olarak, RBF çekirdeği şu şekilde tanımlanır:
   
   \[ K(x_1, x_2) = \exp(-\gamma ||x_1 - x_2||^2) \]

   Burada:
   - \( x_1 \) ve \( x_2 \) veri noktalarıdır.
   - \( \gamma \) RBF çekirdeği için bir hiperparametredir.