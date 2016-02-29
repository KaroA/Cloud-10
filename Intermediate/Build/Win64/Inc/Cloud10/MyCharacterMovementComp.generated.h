// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

#ifdef CLOUD10_MyCharacterMovementComp_generated_h
#error "MyCharacterMovementComp.generated.h already included, missing '#pragma once' in MyCharacterMovementComp.h"
#endif
#define CLOUD10_MyCharacterMovementComp_generated_h

#define UMyCharacterMovementComp_EVENTPARMS
#define UMyCharacterMovementComp_RPC_WRAPPERS
#define UMyCharacterMovementComp_RPC_WRAPPERS_NO_PURE_DECLS \
	static inline void StaticChecks_Implementation_Validate() \
	{ \
	}


#define UMyCharacterMovementComp_CALLBACK_WRAPPERS
#define UMyCharacterMovementComp_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUMyCharacterMovementComp(); \
	friend CLOUD10_API class UClass* Z_Construct_UClass_UMyCharacterMovementComp(); \
	public: \
	DECLARE_CLASS(UMyCharacterMovementComp, UCharacterMovementComponent, COMPILED_IN_FLAGS(0), 0, Cloud10, NO_API) \
	DECLARE_SERIALIZER(UMyCharacterMovementComp) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	UObject* _getUObject() const { return const_cast<UMyCharacterMovementComp*>(this); }


#define UMyCharacterMovementComp_INCLASS \
	private: \
	static void StaticRegisterNativesUMyCharacterMovementComp(); \
	friend CLOUD10_API class UClass* Z_Construct_UClass_UMyCharacterMovementComp(); \
	public: \
	DECLARE_CLASS(UMyCharacterMovementComp, UCharacterMovementComponent, COMPILED_IN_FLAGS(0), 0, Cloud10, NO_API) \
	DECLARE_SERIALIZER(UMyCharacterMovementComp) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	UObject* _getUObject() const { return const_cast<UMyCharacterMovementComp*>(this); }


#define UMyCharacterMovementComp_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyCharacterMovementComp(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyCharacterMovementComp) \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API UMyCharacterMovementComp(const UMyCharacterMovementComp& InCopy); \
public:


#define UMyCharacterMovementComp_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API UMyCharacterMovementComp(const UMyCharacterMovementComp& InCopy); \
public: \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyCharacterMovementComp)


#undef UCLASS_CURRENT_FILE_NAME
#define UCLASS_CURRENT_FILE_NAME UMyCharacterMovementComp


#undef UCLASS
#undef UINTERFACE
#if UE_BUILD_DOCS
#define UCLASS(...)
#else
#define UCLASS(...) \
UMyCharacterMovementComp_EVENTPARMS
#endif


#undef GENERATED_UCLASS_BODY
#undef GENERATED_BODY
#undef GENERATED_IINTERFACE_BODY
#define GENERATED_UCLASS_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UMyCharacterMovementComp_RPC_WRAPPERS \
	UMyCharacterMovementComp_CALLBACK_WRAPPERS \
	UMyCharacterMovementComp_INCLASS \
	UMyCharacterMovementComp_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_POP


#define GENERATED_BODY() \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UMyCharacterMovementComp_RPC_WRAPPERS_NO_PURE_DECLS \
	UMyCharacterMovementComp_CALLBACK_WRAPPERS \
	UMyCharacterMovementComp_INCLASS_NO_PURE_DECLS \
	UMyCharacterMovementComp_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_POP


#define FOREACH_ENUM_TCUSTOMMOVEMENTMODE(op) \
	op(TMOVE_Diving) \
	op(TMOVE_Walking) 
