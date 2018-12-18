# binarySearchTree
## Açıklama
#### İkili ağaçların (Binary Tree) özel bir hali olan ikili arama ağaçlarında, düğümlerde duran bilgilerin birbirine göre küçüklük büyüklük ilişkisi bulunmalıdır. Örneğin tam sayılardan(integer) oluşan veriler tutulacaksa bu verilerin aralarında küçük-büyükilişkisi bulunmaktadır.

#### İkili arama ağacı, her düğümün solundaki koldan ulaşılabilecek bütün verilerin düğümün değerinden küçük, sağ kolundan ulaşılabilecek verilerin değerinin o düğümün değerinden büyük olmasını şart koşar.

## Kod:
#### Bu kod c programlama dilinde yazılmıştır. Binary tree üzerinde ekleme çıkarma silme arama gibi işlemleri gerçekleştirmektedir.
```
typedef struct agac {
    int eleman;
    int yukseklik;
    struct agac *sag,*sol;
}Agaclar;
```
    #### Burada eleman o nodun değerini sağ ve sol pointerlerı o nodun sağ noduu ve sol d-nodunu yükseklik ise yine o nodun yüksekliğini tutan verillerdir.
    
