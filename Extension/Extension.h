#ifndef __ROTATE_H
#define __ROTATE_H

#if defined(_WIN32) 
#	if defined(SampleExtension_EXPORTS)
#		define SAMPLE_EXTENSION_EXPORT __declspec(dllexport)
#	else
#		define SAMPLE_EXTENSION_EXPORT __declspec(dllimport)
#	endif // SampleExtenstion_EXPORTS
#else // defined(_WIN32)
#	define SAMPLE_EXTENSION_EXPORT
#endif

#if SH_EDITOR

#define SH_EXTENSION_INITIALIZE		PluginInitialize
#define SH_EXTENSION_RELEASE		PluginRelease

extern "C"
{
	SAMPLE_EXTENSION_EXPORT void	SH_EXTENSION_INITIALIZE		(void);
	SAMPLE_EXTENSION_EXPORT void	SH_EXTENSION_RELEASE		(void);
}
#endif // SH_EDITOR

#endif // __ROTATE_H