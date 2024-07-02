// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlateBasics.h"
#include "SlateExtras.h"
#include "MenuHUD.h"

/**
 * 
 */
class SMainMenuWidget:public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainMenuWidget) {}

	SLATE_ARGUMENT(TWeakObjectPtr<class AMenuHUD>, OwingHUD)

	SLATE_END_ARGS()


		void Construct(const FArguments& InArgs);

	FReply OnPlayClicked()	const;
	FReply OnQuitClicked()	const;


	TWeakObjectPtr<class AMenuHUD> OwingHUD;

	virtual bool SupportsKeyboardFocus() const override { return true; };

	SMainMenuWidget();
	~SMainMenuWidget();
};
