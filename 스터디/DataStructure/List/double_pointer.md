#이중 포인터?

링크드 리스트를 공부하다 보면 인자로 헤드 포인터를 받을 때 더블 포인터가 필요하다고 할 때가 있다.  
이는 구조체를 선언할 때 첫번째로 node struct를 선언하고,  
두번째로 linked_list struct를 선언하여 인자로 받지 않고 node struct만 사용 했을때 명시적으로 이중 포인터가 필요하게 된다.  


자세한 사항은 해당 링크를 참고하라. -> http://www.slideshare.net/donggyupark2/10-64151270

##암시적으로 사용하게 되는 포인터의 포인터

하지만 linked_list로 선언한 구조체의 *포인터*를 넘기면 이야기가 달라지는데,  
사실 이 과정에서 암시적으로 당신은 **이중 포인터**를 사용한 것이다.  
따라서 스택에 할당 되었던 리스트 포인터 변수를 활용해서   
멤버 포인터(head, tail, cur, before등등)에 접근하여 값을 변경하면 이는 결국  
스택 바깥에 있는 데이터를 바꾸는 것이고, 함수가 종료되어도 그 결과는 유지된다.


하지만 리스트에 감싸서 인자로 넘기는 것이 아니라면 명시적으로 이중 포인터로 데이터를 조작해야 한다.  
그래야 함수 내부의 동작(스택 프레임 안쪽에서 생기는 일)의 바깥에도 영향을 끼칠 수 있게 된다.  

