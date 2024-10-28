#ifndef __OS__GUI__LAIN_H
#define __OS__GUI__LAIN_H

#include <drivers/vga.h>
#include <drivers/mouse.h>
#include <drivers/keyboard.h>
#include <memorymanagement.h>


#define LAIN_INPUT_EVENT_MOUSEMOVE 0
#define LAIN_INPUT_EVENT_MOUSEUP   1
#define LAIN_INPUT_EVENT_MOUSEDOWN 2
#define LAIN_INPUT_EVENT_KEYDOWN   3
#define LAIN_INPUT_EVENT_KEYUP     4

namespace os{
    namespace gui {
        template <typename T>
        class LainStack{
            private:
            T* start = 0;
            common::uint16_t maxsize = 0;
            common::uint16_t count = 0;

            public:
            LainStack();
            LainStack(common::uint16_t size);
            ~LainStack();

            void Push(T value);
            void Pop();
            T Pull();
            void Clear();

            bool Empty();
            common::uint16_t Count();

            T& Top();
            T* Start();
        };

        struct LainInputEvent
        {
            common::int8_t type;
            common::int32_t x;
            common::int32_t y;
            char key;
            LainInputEvent(){

            }
            LainInputEvent(common::uint8_t type, common::int32_t x, common::int32_t y){
                this->type = type;
                this->x = x;
                this->y = y;
            }

            LainInputEvent(common::uint8_t type, char value){
                this->type = type;
                this->key = value;
            }
        };
        

        class LainInput : public drivers::MouseEventHandler, public drivers::KeyboardEventHandler{
            public:
            LainStack<LainInputEvent>* events;

            LainInput();
            ~LainInput();

            void OnMouseDown(common::uint8_t button) override;
			void OnMouseUp(common::uint8_t button) override;
			void OnMouseMove(int x, int y) override;
			void OnKeyDown(char str) override;
			void OnKeyUp(char str) override;
        };

        class LainDesktop{
            private:
            os::drivers::VideoGraphicsArray* vga;
            common::uint8_t t_ui8t1 = 0x3F;
            LainInputEvent t_lie1;
            common::int16_t mx, my; 
            public:
            LainInput* input;

            LainDesktop();
            ~LainDesktop();

            LainInput* GetInput();

            void Init();
            void Tick();


        };
    }
}


#endif