// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAnimInstance.h"

#include "GameFramework/PawnMovementComponent.h"

void UMainAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (Pawn == nullptr)
		Pawn = TryGetPawnOwner();

	
}

void UMainAnimInstance::UpdateAnimationProperties()
{
	if (Pawn == nullptr)
		Pawn = TryGetPawnOwner();

	if (Pawn)
	{
		FVector Velocity = Pawn->GetVelocity();
		FVector LateralVelocity = FVector(Velocity.X, Velocity.Y, 0.0f);
		movementSpeed = LateralVelocity.Size();

		bIsAir = Pawn->GetMovementComponent()->IsFalling();
	}
}
