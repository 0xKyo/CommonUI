// 0xKyo


#include "Widgets/Widget_PrimaryLayout.h"

UCommonActivatableWidgetContainerBase* UWidget_PrimaryLayout::FindWidgetStackByTag(FGameplayTag InTag) const
{
	checkf(RegisteredWidgetStackMap.Contains(InTag), TEXT("Widget stack with tag %s is not registered in the primary layout."), *InTag.ToString());
	return RegisteredWidgetStackMap.FindRef(InTag);
}

void UWidget_PrimaryLayout::RegisterWidgetStack(UPARAM(meta = (Categories = "Frontend.WidgetStack")) FGameplayTag InStackTag, UCommonActivatableWidgetContainerBase* InStack)
{
	// We don't want to register widget stacks in design time, as they will be serialized and cause issues when the game is run.
	if (!IsDesignTime())
	{
		// If the stack tag is not already registered, add it to the map.
		if (!RegisteredWidgetStackMap.Contains(InStackTag))
		{
			RegisteredWidgetStackMap.Add(InStackTag, InStack);
		}
	}
}
