#include "Widgets/Widget_ActivatableBase.h"

#include "Controllers/FrontEndPlayerController.h"

AFrontendPlayerController* UWidget_ActivatableBase::GetOwningFrontendPlayerController()
{
	if (CachedOwningFrontendPC.IsValid())
	{
		CachedOwningFrontendPC = GetOwningPlayer<AFrontendPlayerController>();
	}

	return CachedOwningFrontendPC.IsValid() ? CachedOwningFrontendPC.Get() : nullptr;
}
