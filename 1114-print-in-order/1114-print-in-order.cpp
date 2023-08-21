class Foo {
public:
    mutex m;
    condition_variable c;
    int turn;
    Foo() {
        turn =0;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        
        printFirst();
        turn =1;
        c.notify_all();
        
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        unique_lock<mutex>lock(m);
        while(turn !=1){
            c.wait(lock);
        }
        printSecond();
        turn =2;
        c.notify_all();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        unique_lock<mutex>lock(m);
        while(turn !=2){
            c.wait(lock);
        }
       
        
        printThird();
        
    }
};