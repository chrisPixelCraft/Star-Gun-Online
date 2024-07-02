// Fill out your copyright notice in the Description page of Project Settings.


#include "SMainMenuWidget.h"
#include "MenuHUD.h"
#include "GameFramework/PlayerController.h"

#define LOCTEXT_NAMESPACE "MainMenu"

void SMainMenuWidget::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	OwingHUD = InArgs._OwingHUD;

	const FMargin ContentPadding = FMargin(500.f, 300.f);
	const FMargin ButtonPadding = FMargin(10.f);

	const FText TitleText = LOCTEXT("GameTitle", "Starry Gungame");
	const FText PlayText = LOCTEXT("PlayGame", "Play");
	const FText SettingText = LOCTEXT("Settnigs", "Settings");
	const FText QuitText = LOCTEXT("QuitGame", "Quit Game");


	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 40.f;

	FSlateFontInfo TitleTextStyle = ButtonTextStyle;
	TitleTextStyle.Size = 60.f;


	ChildSlot[
		SNew(SOverlay)
		+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)[
			SNew(SImage)
			.ColorAndOpacity(FColor::Black)
		]

		 + SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(ContentPadding)[
				SNew(SVerticalBox)

				//Title text
				+ SVerticalBox::Slot()[
					SNew(STextBlock)
						.Font(TitleTextStyle)
						.Text(TitleText)
						.Justification(ETextJustify::Center)
				]

				//play button
				+ SVerticalBox::Slot()
				.Padding(ButtonPadding)[
					SNew(SButton)
						.OnClicked(this,&SMainMenuWidget::OnPlayClicked)
						[
						SNew(STextBlock)
						.Font(ButtonTextStyle)
						.Text(PlayText)
						.Justification(ETextJustify::Center)
					]
				]
				//settings button
				+ SVerticalBox::Slot()
				.Padding(ButtonPadding)[
					SNew(SButton)[
						SNew(STextBlock)
						.Font(ButtonTextStyle)
						.Text(SettingText)
						.Justification(ETextJustify::Center)
					]
				]
				//Quit button
				+ SVerticalBox::Slot()
				.Padding(ButtonPadding)[
					SNew(SButton)
						.OnClicked(this, &SMainMenuWidget::OnQuitClicked)
						[
						SNew(STextBlock)
						.Font(ButtonTextStyle)
						.Text(QuitText)
						.Justification(ETextJustify::Center)
					]
				]
			]

		
	];
}

FReply SMainMenuWidget::OnPlayClicked() const
{
	//UE_LOG(LogTemp,Warning, TEXT(""))
	if (OwingHUD.IsValid()) {
			OwingHUD->RemoveMenu();
	}
	return FReply::Handled();
}

FReply SMainMenuWidget::OnQuitClicked() const
{
	if (OwingHUD.IsValid()) {
		if (APlayerController* PC = OwingHUD->PlayerOwner) {
			PC->ConsoleCommand("quit");
		}
	}
	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE

SMainMenuWidget::SMainMenuWidget()
{
}

SMainMenuWidget::~SMainMenuWidget()
{
}
