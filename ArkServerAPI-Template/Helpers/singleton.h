#pragma once
/**
 * Basic Singleton class.
 *
 * ...
 *
 * @tparam T The type you wish to get a Singleton of.
 *
 */
template <typename T>
class Singleton
{
public:
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&) = delete;
    /**
     * Gets a reference to the Singleton.
     *
     * ...
     *
     * @returns T An instance of the Singleton.
     *
     */
	static T& Get()
	{
		static T instance; return instance;
	}
private:
    Singleton() = default;
    ~Singleton() = default;
};