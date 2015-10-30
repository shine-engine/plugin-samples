#ifndef __EXTENSION_H
#define __EXTENSION_H

#if defined(_WIN32) 
#	if defined(SampleExtension_EXPORTS)
#		define SAMPLE_EXTENSION_EXPORT __declspec(dllexport)
#	else
#		define SAMPLE_EXTENSION_EXPORT __declspec(dllimport)
#	endif // SampleExtenstion_EXPORTS
#else // defined(_WIN32)
#	define SAMPLE_EXTENSION_EXPORT
#endif

extern "C"
{
	SAMPLE_EXTENSION_EXPORT void	ExtensionInitialize		(void);
	SAMPLE_EXTENSION_EXPORT void	ExtensionRelease		(void);
}

#endif // __EXTENSION_H