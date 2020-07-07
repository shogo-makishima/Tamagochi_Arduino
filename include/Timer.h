
class Timer{
	public:
	float time = 0.0;

	Timer(float seconds) {
		time = seconds;
		m_timing = millis();
		m_time = time;
	}

	void Update() {
		if (time > 0) { 
			time -= millis() - m_timing;
			m_timing = millis();
		}
	}

	void Reset() {
		time = m_time;
		m_timing = millis();
	}

	private:
	float m_time = 0;
	unsigned long m_timing;
};