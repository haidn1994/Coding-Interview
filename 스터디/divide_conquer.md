#분할 정복법이란?

분할 정복법이란 재귀(여러 갈래로 뻗어나가는)에 기초한, 그리고 가장 유명한 알고리즘 디자인 패러다임이다.  
재귀, 동적 계획법과 마찬가지로 크고 거대한 문제를 수많은 작은 문제로 쪼개어 하나씩 해결한 다음,  
그 답들을 토대로 원래 해결하고자 했던 문제의 답을 해결하는 알고리즘 디자인 패러다임이다.  


분할 정복법이 동적 프로그래밍과 다른 점은 메모이제이션을 활용하지 않는다는 점을 꼽을 수 있겠다.  
그렇다면 단순하게 재귀함수를 활용하는 것과 어떤 것이 다를까?  


일반적인 재귀 호출은 문제를 한 조각과 나머지 전체로 나누는데,   
이와 달리, 분할 정복법은 문제를 거의 같은 크기의 부분 문제로 나누는 것이 특히 두드러지는 차이점이다.  

##과정
또한 분할 정복법은 대개 다음 3가지 요소를 갖추고 있다.

* 문제를 더 작은 문제로 분할하는 과정(divide)
* 각 문제에 대해 구한 답을 원래 풀고자 했던 문제에 대한 답으로 병합하는 과정(merge)
* 더이상 답을 분할 하지 않고 곧장 풀 수 있는 매우 작은 문제(base case)

또는 다음과 같은 3가지 과정을 거친다고 생각해도 좋다.

1. 분할(divide): 해결이 용이한 단계까지 문제를 분할해 나간다.
2. 정복(conquer): 해결이 용이한 수준까지 분할된 문제를 해결한다.
3. 결합(combine): 분할해서 해결한 결과를 결합하여 마무리한다.

##적용조건
여기에 더해서 분할 정복법을 적용하기 위해서는 문제에 몇 가지 특성이 성립해야 한다.  
대표적인 예는 다음과 같다.  

1. 문제를 둘 이상의 부분 문제로 나누는 자연스러운 방법이 있어야 한다.
2. 부분 문제의 답을 조합하여 원래 문제의 답을 계산하는 효율적인 방법이 있어야 한다.

##장점

이제 분할 정복으로 얻을수 있는 장점에 대해서 알아보자. 대표적인 장점은 다음과 같다.

###어려운 문제를 해결
분할 정복의 핵심으로 애초에 어려운 문제를 작은 부분 문제로 쪼개어  
해결하자는 명목으로 만들어진 알고리즘 디자인 패러다임이 바로 분할과 정복이다.  

###효율적인 알고리즘
분할 정복 패러다임은 패러다임 그 자체로 문제를 보다 효율적으로 해결하는데 영감을 제공하기도 한다.  
예를 들어 카라츄바의 곱셈법, 스트라센 알고리즘등이 있다.   

###병렬성
분할 정복법을 적용한 알고리즘은 멀티 프로세서를 활용하는데 있어서 효과적이다.  
왜냐하면 각각의 부분 문제들은 각각의 프로세서에서 독립적으로 처리될 수 있기 때문이다.  

###메모리 접근
분할 정복법은 메모리 캐시를 이용하는데 매우 효율적이다.  
그 이유는 부분 문제가 충분히 작다면 메모리(RAM)에 액세스하지 않고도,  
부분 문제를 캐시 안에서 충분하게 해결하는 것이 가능하기 때문이다.  

##구현 이슈

###명시적 스택

###스택 사이즈

###기저 문제(base case) 선택

###반복되는 부분 문제 공유

###'충분히 작은 문제'란?



