#pragma once
#include "Engine.h"

namespace Vetche2D {

	template<typename From, typename To>
	To * const & CastTo(From * const & from)
	{
		return dynamic_cast<To*>(from);
	}

	template<typename Current, typename Check>
	bool IsType(Current * const & current)
	{
		return current == dynamic_cast<Check*>(current);
	}
}