template <class T>
std::vector<T> Button<T>::registered;

template <class T>
Button<T>::Button(int switchPin)
{
  switch_.setPin(switchPin);
}

template <class T>
void Button<T>::read()
{
  for (size_t i = 0; i < registered.size(); i++)
  {
    registered[i].handlePress();
  }
}

template <class T>
int Button<T>::registeredCount()
{
  registered.size();
}
