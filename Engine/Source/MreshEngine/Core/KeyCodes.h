#pragma once

namespace MreshEngine
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space               = 32,
		Apostrophe          = 39, /* ' */
		Comma               = 44, /* , */
		Minus               = 45, /* - */
		Period              = 46, /* . */
		Slash               = 47, /* / */

		D0                  = 48, /* 0 */
		D1                  = 49, /* 1 */
		D2                  = 50, /* 2 */
		D3                  = 51, /* 3 */
		D4                  = 52, /* 4 */
		D5                  = 53, /* 5 */
		D6                  = 54, /* 6 */
		D7                  = 55, /* 7 */
		D8                  = 56, /* 8 */
		D9                  = 57, /* 9 */

		Semicolon           = 59, /* ; */
		Equal               = 61, /* = */

		A                   = 65,
		B                   = 66,
		C                   = 67,
		D                   = 68,
		E                   = 69,
		F                   = 70,
		G                   = 71,
		H                   = 72,
		I                   = 73,
		J                   = 74,
		K                   = 75,
		L                   = 76,
		M                   = 77,
		N                   = 78,
		O                   = 79,
		P                   = 80,
		Q                   = 81,
		R                   = 82,
		S                   = 83,
		T                   = 84,
		U                   = 85,
		V                   = 86,
		W                   = 87,
		X                   = 88,
		Y                   = 89,
		Z                   = 90,

		LeftBracket         = 91,  /* [ */
		Backslash           = 92,  /* \ */
		RightBracket        = 93,  /* ] */
		GraveAccent         = 96,  /* ` */

		World1              = 161, /* non-US #1 */
		World2              = 162, /* non-US #2 */

		/* Function keys */
		Escape              = 256,
		Enter               = 257,
		Tab                 = 258,
		Backspace           = 259,
		Insert              = 260,
		Delete              = 261,
		Right               = 262,
		Left                = 263,
		Down                = 264,
		Up                  = 265,
		PageUp              = 266,
		PageDown            = 267,
		Home                = 268,
		End                 = 269,
		CapsLock            = 280,
		ScrollLock          = 281,
		NumLock             = 282,
		PrintScreen         = 283,
		Pause               = 284,
		F1                  = 290,
		F2                  = 291,
		F3                  = 292,
		F4                  = 293,
		F5                  = 294,
		F6                  = 295,
		F7                  = 296,
		F8                  = 297,
		F9                  = 298,
		F10                 = 299,
		F11                 = 300,
		F12                 = 301,
		F13                 = 302,
		F14                 = 303,
		F15                 = 304,
		F16                 = 305,
		F17                 = 306,
		F18                 = 307,
		F19                 = 308,
		F20                 = 309,
		F21                 = 310,
		F22                 = 311,
		F23                 = 312,
		F24                 = 313,
		F25                 = 314,

		/* Keypad */
		KP0                 = 320,
		KP1                 = 321,
		KP2                 = 322,
		KP3                 = 323,
		KP4                 = 324,
		KP5                 = 325,
		KP6                 = 326,
		KP7                 = 327,
		KP8                 = 328,
		KP9                 = 329,
		KPDecimal           = 330,
		KPDivide            = 331,
		KPMultiply          = 332,
		KPSubtract          = 333,
		KPAdd               = 334,
		KPEnter             = 335,
		KPEqual             = 336,

		LeftShift           = 340,
		LeftControl         = 341,
		LeftAlt             = 342,
		LeftSuper           = 343,
		RightShift          = 344,
		RightControl        = 345,
		RightAlt            = 346,
		RightSuper          = 347,
		Menu                = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define ME_KEY_SPACE           ::MreshEngine::Key::Space
#define ME_KEY_APOSTROPHE      ::MreshEngine::Key::Apostrophe    /* ' */
#define ME_KEY_COMMA           ::MreshEngine::Key::Comma         /* , */
#define ME_KEY_MINUS           ::MreshEngine::Key::Minus         /* - */
#define ME_KEY_PERIOD          ::MreshEngine::Key::Period        /* . */
#define ME_KEY_SLASH           ::MreshEngine::Key::Slash         /* / */
#define ME_KEY_0               ::MreshEngine::Key::D0
#define ME_KEY_1               ::MreshEngine::Key::D1
#define ME_KEY_2               ::MreshEngine::Key::D2
#define ME_KEY_3               ::MreshEngine::Key::D3
#define ME_KEY_4               ::MreshEngine::Key::D4
#define ME_KEY_5               ::MreshEngine::Key::D5
#define ME_KEY_6               ::MreshEngine::Key::D6
#define ME_KEY_7               ::MreshEngine::Key::D7
#define ME_KEY_8               ::MreshEngine::Key::D8
#define ME_KEY_9               ::MreshEngine::Key::D9
#define ME_KEY_SEMICOLON       ::MreshEngine::Key::Semicolon     /* ; */
#define ME_KEY_EQUAL           ::MreshEngine::Key::Equal         /* = */
#define ME_KEY_A               ::MreshEngine::Key::A
#define ME_KEY_B               ::MreshEngine::Key::B
#define ME_KEY_C               ::MreshEngine::Key::C
#define ME_KEY_D               ::MreshEngine::Key::D
#define ME_KEY_E               ::MreshEngine::Key::E
#define ME_KEY_F               ::MreshEngine::Key::F
#define ME_KEY_G               ::MreshEngine::Key::G
#define ME_KEY_H               ::MreshEngine::Key::H
#define ME_KEY_I               ::MreshEngine::Key::I
#define ME_KEY_J               ::MreshEngine::Key::J
#define ME_KEY_K               ::MreshEngine::Key::K
#define ME_KEY_L               ::MreshEngine::Key::L
#define ME_KEY_M               ::MreshEngine::Key::M
#define ME_KEY_N               ::MreshEngine::Key::N
#define ME_KEY_O               ::MreshEngine::Key::O
#define ME_KEY_P               ::MreshEngine::Key::P
#define ME_KEY_Q               ::MreshEngine::Key::Q
#define ME_KEY_R               ::MreshEngine::Key::R
#define ME_KEY_S               ::MreshEngine::Key::S
#define ME_KEY_T               ::MreshEngine::Key::T
#define ME_KEY_U               ::MreshEngine::Key::U
#define ME_KEY_V               ::MreshEngine::Key::V
#define ME_KEY_W               ::MreshEngine::Key::W
#define ME_KEY_X               ::MreshEngine::Key::X
#define ME_KEY_Y               ::MreshEngine::Key::Y
#define ME_KEY_Z               ::MreshEngine::Key::Z
#define ME_KEY_LEFT_BRACKET    ::MreshEngine::Key::LeftBracket   /* [ */
#define ME_KEY_BACKSLASH       ::MreshEngine::Key::Backslash     /* \ */
#define ME_KEY_RIGHT_BRACKET   ::MreshEngine::Key::RightBracket  /* ] */
#define ME_KEY_GRAVE_ACCENT    ::MreshEngine::Key::GraveAccent   /* ` */
#define ME_KEY_WORLD_1         ::MreshEngine::Key::World1        /* non-US #1 */
#define ME_KEY_WORLD_2         ::MreshEngine::Key::World2        /* non-US #2 */

/* Function keys */
#define ME_KEY_ESCAPE          ::MreshEngine::Key::Escape
#define ME_KEY_ENTER           ::MreshEngine::Key::Enter
#define ME_KEY_TAB             ::MreshEngine::Key::Tab
#define ME_KEY_BACKSPACE       ::MreshEngine::Key::Backspace
#define ME_KEY_INSERT          ::MreshEngine::Key::Insert
#define ME_KEY_DELETE          ::MreshEngine::Key::Delete
#define ME_KEY_RIGHT           ::MreshEngine::Key::Right
#define ME_KEY_LEFT            ::MreshEngine::Key::Left
#define ME_KEY_DOWN            ::MreshEngine::Key::Down
#define ME_KEY_UP              ::MreshEngine::Key::Up
#define ME_KEY_PAGE_UP         ::MreshEngine::Key::PageUp
#define ME_KEY_PAGE_DOWN       ::MreshEngine::Key::PageDown
#define ME_KEY_HOME            ::MreshEngine::Key::Home
#define ME_KEY_END             ::MreshEngine::Key::End
#define ME_KEY_CAPS_LOCK       ::MreshEngine::Key::CapsLock
#define ME_KEY_SCROLL_LOCK     ::MreshEngine::Key::ScrollLock
#define ME_KEY_NUM_LOCK        ::MreshEngine::Key::NumLock
#define ME_KEY_PRINT_SCREEN    ::MreshEngine::Key::PrintScreen
#define ME_KEY_PAUSE           ::MreshEngine::Key::Pause
#define ME_KEY_F1              ::MreshEngine::Key::F1
#define ME_KEY_F2              ::MreshEngine::Key::F2
#define ME_KEY_F3              ::MreshEngine::Key::F3
#define ME_KEY_F4              ::MreshEngine::Key::F4
#define ME_KEY_F5              ::MreshEngine::Key::F5
#define ME_KEY_F6              ::MreshEngine::Key::F6
#define ME_KEY_F7              ::MreshEngine::Key::F7
#define ME_KEY_F8              ::MreshEngine::Key::F8
#define ME_KEY_F9              ::MreshEngine::Key::F9
#define ME_KEY_F10             ::MreshEngine::Key::F10
#define ME_KEY_F11             ::MreshEngine::Key::F11
#define ME_KEY_F12             ::MreshEngine::Key::F12
#define ME_KEY_F13             ::MreshEngine::Key::F13
#define ME_KEY_F14             ::MreshEngine::Key::F14
#define ME_KEY_F15             ::MreshEngine::Key::F15
#define ME_KEY_F16             ::MreshEngine::Key::F16
#define ME_KEY_F17             ::MreshEngine::Key::F17
#define ME_KEY_F18             ::MreshEngine::Key::F18
#define ME_KEY_F19             ::MreshEngine::Key::F19
#define ME_KEY_F20             ::MreshEngine::Key::F20
#define ME_KEY_F21             ::MreshEngine::Key::F21
#define ME_KEY_F22             ::MreshEngine::Key::F22
#define ME_KEY_F23             ::MreshEngine::Key::F23
#define ME_KEY_F24             ::MreshEngine::Key::F24
#define ME_KEY_F25             ::MreshEngine::Key::F25

/* Keypad */
#define ME_KEY_KP_0            ::MreshEngine::Key::KP0
#define ME_KEY_KP_1            ::MreshEngine::Key::KP1
#define ME_KEY_KP_2            ::MreshEngine::Key::KP2
#define ME_KEY_KP_3            ::MreshEngine::Key::KP3
#define ME_KEY_KP_4            ::MreshEngine::Key::KP4
#define ME_KEY_KP_5            ::MreshEngine::Key::KP5
#define ME_KEY_KP_6            ::MreshEngine::Key::KP6
#define ME_KEY_KP_7            ::MreshEngine::Key::KP7
#define ME_KEY_KP_8            ::MreshEngine::Key::KP8
#define ME_KEY_KP_9            ::MreshEngine::Key::KP9
#define ME_KEY_KP_DECIMAL      ::MreshEngine::Key::KPDecimal
#define ME_KEY_KP_DIVIDE       ::MreshEngine::Key::KPDivide
#define ME_KEY_KP_MULTIPLY     ::MreshEngine::Key::KPMultiply
#define ME_KEY_KP_SUBTRACT     ::MreshEngine::Key::KPSubtract
#define ME_KEY_KP_ADD          ::MreshEngine::Key::KPAdd
#define ME_KEY_KP_ENTER        ::MreshEngine::Key::KPEnter
#define ME_KEY_KP_EQUAL        ::MreshEngine::Key::KPEqual

#define ME_KEY_LEFT_SHIFT      ::MreshEngine::Key::LeftShift
#define ME_KEY_LEFT_CONTROL    ::MreshEngine::Key::LeftControl
#define ME_KEY_LEFT_ALT        ::MreshEngine::Key::LeftAlt
#define ME_KEY_LEFT_SUPER      ::MreshEngine::Key::LeftSuper
#define ME_KEY_RIGHT_SHIFT     ::MreshEngine::Key::RightShift
#define ME_KEY_RIGHT_CONTROL   ::MreshEngine::Key::RightControl
#define ME_KEY_RIGHT_ALT       ::MreshEngine::Key::RightAlt
#define ME_KEY_RIGHT_SUPER     ::MreshEngine::Key::RightSuper
#define ME_KEY_MENU            ::MreshEngine::Key::Menu
