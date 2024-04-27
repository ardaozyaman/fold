1. **Eğitim Fonksiyonu:**
   Eğitim fonksiyonu, destek vektör makinelerini eğitmek için kullanılır. Bu fonksiyon, verilen eğitim veri setiyle birlikte destek vektör makinesinin parametrelerini öğrenir. Matematiksel olarak, eğitim süreci aşağıdaki adımları içerir:
  
   a. Çekirdek matrisini hesapla:
      <p align="center"><img src="https://latex.codecogs.com/gif.latex?K_{ij}%20=%20\exp(-\gamma%20||x_i%20-%20x_j||^2)"/></p>  
  
  
   b. Alpha (α) vektörlerini güncelle:
      <p align="center"><img src="https://latex.codecogs.com/gif.latex?\alpha_i%20=%20\alpha_i%20+%20\eta"/></p>  
  
      <p align="center"><img src="https://latex.codecogs.com/gif.latex?b%20=%20b%20+%20\eta%20y_i"/></p>  
  
  
   Burada:
   - <img src="https://latex.codecogs.com/gif.latex?x_i"/> ve <img src="https://latex.codecogs.com/gif.latex?x_j"/> eğitim veri setindeki i ve j indisli örneklerdir.
   - <img src="https://latex.codecogs.com/gif.latex?\gamma"/> RBF çekirdeği için bir hiperparametredir.
   - <img src="https://latex.codecogs.com/gif.latex?\alpha_i"/> destek vektörlerinin katsayılarıdır.
   - <img src="https://latex.codecogs.com/gif.latex?\eta"/> öğrenme hızıdır.
   - <img src="https://latex.codecogs.com/gif.latex?y_i"/> eğitim veri setindeki i indisli örneğin sınıf etiketidir.
  
2. **Tahmin Fonksiyonu:**
   Tahmin fonksiyonu, eğitilmiş destek vektör makinesi kullanılarak yeni veri noktalarının sınıflandırılması için kullanılır. Bu fonksiyon, verilen bir veri noktasının sınıfını tahmin eder. Matematiksel olarak, tahmin süreci şu şekilde yapılır:
  
   <p align="center"><img src="https://latex.codecogs.com/gif.latex?f(x)%20=%20b%20+%20\sum_{i=1}^{n_{\text{SV}}}%20\alpha_i%20y_i%20K(x,%20x_i)"/></p>  
  
   <p align="center"><img src="https://latex.codecogs.com/gif.latex?\text{Tahmin}(x)%20=%20\text{sgn}(f(x))"/></p>  
  
  
   Burada:
   - <img src="https://latex.codecogs.com/gif.latex?f(x)"/> verilen veri noktasının karar fonksiyonudur.
   - <img src="https://latex.codecogs.com/gif.latex?b"/> yanlılık terimidir.
   - <img src="https://latex.codecogs.com/gif.latex?\alpha_i"/> destek vektörlerinin katsayılarıdır.
   - <img src="https://latex.codecogs.com/gif.latex?y_i"/> destek vektörlerinin sınıf etiketleridir.
   - <img src="https://latex.codecogs.com/gif.latex?K(x,%20x_i)"/> RBF çekirdeği değeridir.
   - <img src="https://latex.codecogs.com/gif.latex?\text{sgn}"/> işareti belirtir.
  
3. **RBF (Gaussian) Çekirdeği:**
   RBF çekirdeği, iki veri noktası arasındaki benzerliği ölçmek için kullanılır. Matematiksel olarak, RBF çekirdeği şu şekilde tanımlanır:
  
   <p align="center"><img src="https://latex.codecogs.com/gif.latex?K(x_1,%20x_2)%20=%20\exp(-\gamma%20||x_1%20-%20x_2||^2)"/></p>  
  
  
   Burada:
   - <img src="https://latex.codecogs.com/gif.latex?x_1"/> ve <img src="https://latex.codecogs.com/gif.latex?x_2"/> veri noktalarıdır.
   - <img src="https://latex.codecogs.com/gif.latex?\gamma"/> RBF çekirdeği için bir hiperparametredir.
  