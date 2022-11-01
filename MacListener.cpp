// 1. 손님과 맥도날드 가게가있는데, 손님이 맥도날드에서 빅맥을 구매를하고, 햄버거가 완료될때까지 기다려야함.
// mutex, conditon_variable, callback, thread
//맥도날드는 구매를 했다는 API가 호출이되면, 내부에서 3초를 쉬고 만들었다고 보내준다(onCompleteHamburger).
#include <iostream>
#include <condition_variable>
#include <thread>
#include <mutex>
#include <Windows.h>
#include <string>

Parent Inherit Parameter

    using namespace std::chrono_literals;
std::mutex mtx;
std::condition_variable m_cv;

class IPurchaseListener
{
public:
    virtual void onCompleteHamburger(std::string const burger) = 0;
};

class CustomerListener : public IPurchaseListener
{
    void onCompleteHamburger(std::string const burger) override
    {
    }
};

class Customer : public PurchaseListener
{
public:
    void onCompleteHamburger(std::string const burger) override
    {
        std::cout << (burger + " 야호 집에가자") << std::endl;
        m_isCompleted = true;
        m_cv.notify_one();
    }
    void waitBigmac()
    {
        std::unique_lock<std::mutex> lck(mtx);
        m_cv.wait(lck, []
                  { return m_isCompleted; });
    }

    void antherMethod();
    prviate : Bool m_isCompleted;
};

class Mcdonald
{
private:
    PurchaseListener m_listener;

public:
    void setEventListener(PurchaseListener &listener)
    {
        m_listener = listener;
    }
    void purchase(std::string const burger)
    {
        std::cout << "주문이 정상적으로 접수되었습니다" << std::endl;
        Sleep(3000);
        std::cout << "버거가 완료되었습니다" << std::endl;
        m_listener.onCompleteHamburger(burger);
    }
};

//메인스레드가 존재하고, 추가적으로 thread존재함.
int main()
{
    shared_ptr<Customer> philip = make_shared<Customer>();
    Mcdonald m;
    m.setEventListener(philip);
    // m.purchase(burger);

    std::thread t1([&]
                   { m.purchase(); });
    // std::thread t1(&Mcdonald::purchase,"bigmac",&m);

    philip.waitBigmac();

    // t1.join(); join 은 쓰지말기.
    return 0;
}