#include <gui/lain.h>
#include <gui/desktop.h>
#include <memorymanagement.h>
#include <hardwarecommunication/interrupts.h>




using namespace os;
using namespace os::common;
using namespace os::drivers;
using namespace os::gui;
using namespace os::filesystem;
using namespace os::hardwarecommunication;


VideoGraphicsArray* GetVideoGraphicsArray();
MemoryManager* GetMemoryManager();
DriverManager* GetDriverManager();
InterruptManager* GetInterruptManager();

template<typename T>
LainStack<T>::LainStack(){

}

template<typename T>
LainStack<T>::LainStack(uint16_t size){
    start = new T[size];
    count = 0;
    maxsize = size;
}

template<typename T>
LainStack<T>::~LainStack(){
    delete start;
}

template<typename T>
void LainStack<T>::Push(T value){
    if(maxsize == count) return;
    start[count] = value;
    count++;
}

template<typename T>
void LainStack<T>::Pop(){
    if(count == 0) return;
    start[count-1].~T();
    count--;
}

template<typename T>
T LainStack<T>::Pull(){
    T result = start[count-1];
    Pop();
    return result;
}

template<typename T>
void LainStack<T>::Clear(){
    while (count) Pop();
    
}

template<typename T>
bool LainStack<T>::Empty(){
    return !count;
}

template<typename T>
uint16_t LainStack<T>::Count(){
    return count;
}

template<typename T>
T& LainStack<T>::Top(){
    return start[count-1];
}

template<typename T>
T* LainStack<T>::Start(){
    return start;
}


LainInput::LainInput() {
    events = new LainStack<LainInputEvent>(256);
}

LainInput::~LainInput(){
    
}

void LainInput::OnMouseMove(int x, int y){
    events->Push(LainInputEvent(LAIN_INPUT_EVENT_MOUSEMOVE,x,y));
    GetVideoGraphicsArray()->PutPixel(5,9,0x36);
}

void LainInput::OnMouseDown(uint8_t Button){
    events->Push(LainInputEvent(LAIN_INPUT_EVENT_MOUSEDOWN,Button));
    GetVideoGraphicsArray()->PutPixel(5,8,0x09);
}

void LainInput::OnMouseUp(uint8_t Button){
    events->Push(LainInputEvent(LAIN_INPUT_EVENT_MOUSEUP,Button));
    GetVideoGraphicsArray()->PutPixel(5,7,0x12);
}

void LainInput::OnKeyDown(char Button){
    events->Push(LainInputEvent(LAIN_INPUT_EVENT_KEYDOWN,Button));
    GetVideoGraphicsArray()->PutPixel(5,6,0x24);
}

void LainInput::OnKeyUp(char Button){
    events->Push(LainInputEvent(LAIN_INPUT_EVENT_KEYUP,Button));
    GetVideoGraphicsArray()->PutPixel(5,5,0x3F);
}

LainDesktop::LainDesktop(){
}


LainDesktop::~LainDesktop(){

}

LainInput* LainDesktop::GetInput(){
    return input;
}


void LainDesktop::Init(){ 
    //Drivers
    input = new LainInput();
    GetDriverManager()->Replace(new LainKeyboardDriver(GetInterruptManager(),input),0);
    GetDriverManager()->Replace(new MouseDriver(GetInterruptManager(),input),1);
    //Misc
    mx = 0;
    my = 0;
    //Video
    vga = GetVideoGraphicsArray();
    vga->SetMode(320, 200, 8);
    vga->SetPalette(VGA_CS_EGA);
    //BackGround
    for(uint16_t y = 0;y < 200;y++) for(uint16_t x = 0;x < 320;x++) vga->PutPixel(x,y,0x38);
}

void LainDesktop::Tick(){
    
    while (!input->events->Empty())
    {
        t_lie1 = input->events->Top();
        
        switch (t_lie1.type)
        {
        case LAIN_INPUT_EVENT_KEYUP:
        t_ui8t1 = t_lie1.key;
        break;
        default:
            break;
        }
        
        input->events->Pop();
    }

    
    for(uint16_t y = 0;y < 200;y++) for(uint16_t x = 0;x < 320;x++) vga->PutPixel(x,y,0x38);

    for(int16_t y = 0;y < 5; y++){
        for(int16_t x = 0;x < 5;x++){
            vga->PutPixel(mx+x,my+y,t_ui8t1);
        }
    }

    vga->DrawToScreen();  
}